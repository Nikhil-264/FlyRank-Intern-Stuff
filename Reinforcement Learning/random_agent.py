import gymnasium as gym
import numpy as np

cliffEnv = gym.make('CliffWalking-v1', render_mode='ansi')

done = False

# Handle both older Gym APIs (returns state) and newer Gym/Gymnasium APIs (returns (state, info))
reset_res = cliffEnv.reset()
state = reset_res[0] if isinstance(reset_res, tuple) else reset_res

while not done:
    # Print the rendered text representation of the environment
    print(cliffEnv.render())
    
    # Use the environment's action space to sample a random action (0-3).
    # This is clean, idiomatic, and avoids NumPy 2.0 scalar conversion errors.
    action = cliffEnv.action_space.sample()
    
    print(state, "-->", ["up", "right", "down", "left"][action])
    
    # Handle both older Gym APIs (returns 4 values) and newer Gym/Gymnasium APIs (returns 5 values)
    step_res = cliffEnv.step(action)
    if len(step_res) == 5:
        state, reward, terminated, truncated, info = step_res
        done = terminated or truncated
    else:
        state, reward, done, _ = step_res

cliffEnv.close()