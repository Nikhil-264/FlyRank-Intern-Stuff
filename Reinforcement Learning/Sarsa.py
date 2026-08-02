import gymnasium as gym
import numpy as np
import pickle as pkl


cliffEnv = gym.make('CliffWalking-v1', render_mode='ansi')

q_table = np.zeros(shape=(48, 4))

def policy(state, explore=0.0):
    # if np.random.random()<explore:
    #     return cliffEnv.action_space.sample()
    # else:
    #     return np.argmax(q_table[state])

    action = int(np.argmax(q_table[state]))
    if np.random.random() <= explore:
        action = int(cliffEnv.action_space.sample())

    return action

# Parameters
EPSILON = 0.1
ALPHA = 0.1
GAMMA = 0.9
NUM_EPISODES = 500

for episode in range(NUM_EPISODES):
    done = False

    total_reward = 0
    episode_length = 0
    reset_res = cliffEnv.reset()
    state = reset_res[0] if isinstance(reset_res, tuple) else reset_res
    action = policy(state)

    while not done:
        step_res = cliffEnv.step(action)
        if len(step_res) == 5:
            next_state, reward, terminated, truncated, info = step_res
            done = terminated or truncated
        else:
            next_state, reward, done, _ = step_res
        next_action = policy(next_state, EPSILON)
        
        q_table[state][action] += ALPHA * (reward + GAMMA * q_table[next_state][next_action] - q_table[state][action])

        state = next_state
        action = next_action

        total_reward += reward
        episode_length += 1
    print(f"Episode {episode} completed with reward {total_reward} and length {episode_length}")
    
cliffEnv.close()
# print(q_table)

pkl.dump(q_table, open("sarsa_q_table.pkl", "wb"))
print("Training completed and Q-table saved to sarsa_q_table.pkl")
