import pygame
import random

# Initialize Pygame
pygame.init()

# Game Constants
SCREEN_WIDTH = 500
SCREEN_HEIGHT = 600
LANE_WIDTH = SCREEN_WIDTH // 3
FPS = 60

# Colors
WHITE = (255, 255, 255)
SAFFRON = (255, 153, 51)  # Modi's Color
BLACK = (0, 0, 0)         # Coin Color
BLUE = (0, 102, 204)      # Gen Z Students' Color
RED = (200, 0, 0)         # Obstacle Color
GRAY = (200, 200, 200)    # Lane lines

# Setup Screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Modi Runner - Simple Version")
clock = pygame.time.Clock()

# Game Variables
player_lane = 1  # 0: Left, 1: Middle, 2: Right
score = 0
game_over = False

# Object speeds
speed = 7
items = [] # Will store both coins and obstacles

def spawn_item():
    lane = random.randint(0, 2)
    # 70% chance for a coin, 30% for an obstacle
    item_type = "coin" if random.random() < 0.7 else "obstacle"
    items.append({"lane": lane, "y": -50, "type": item_type})

# Timer for spawning items
SPAWN_EVENT = pygame.USEREVENT + 1
pygame.time.set_timer(SPAWN_EVENT, 1000)

# Font
font = pygame.font.SysFont("Arial", 24)

# Main Game Loop
running = True
while running:
    screen.fill(WHITE)

    # 1. Event Handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        
        if event.type == pygame.KEYDOWN and not game_over:
            if event.key == pygame.K_LEFT and player_lane > 0:
                player_lane -= 1
            if event.key == pygame.K_RIGHT and player_lane < 2:
                player_lane += 1
        
        if event.type == SPAWN_EVENT and not game_over:
            spawn_item()

    if not game_over:
        # 2. Update Positions
        for item in items[:]:
            item["y"] += speed
            # Remove if off-screen
            if item["y"] > SCREEN_HEIGHT:
                items.remove(item)

        # 3. Collision Detection
        player_rect = pygame.Rect(player_lane * LANE_WIDTH + 20, 450, 60, 80)
        
        for item in items[:]:
            item_rect = pygame.Rect(item["lane"] * LANE_WIDTH + 35, item["y"], 40, 40)
            
            if player_rect.colliderect(item_rect):
                if item["type"] == "coin":
                    score += 10
                    items.remove(item)
                else:
                    game_over = True

    # 4. Drawing
    # Draw Lane Lines
    for i in range(1, 3):
        pygame.draw.line(screen, GRAY, (i * LANE_WIDTH, 0), (i * LANE_WIDTH, SCREEN_HEIGHT), 2)

    # Draw Gen Z Students (The Chasers at the bottom)
    pygame.draw.rect(screen, BLUE, (0, 540, SCREEN_WIDTH, 60))
    student_text = font.render("GEN Z STUDENTS CHASING", True, WHITE)
    screen.blit(student_text, (SCREEN_WIDTH//2 - 120, 560))

    # Draw PM Modi (Player)
    if not game_over:
        pygame.draw.rect(screen, SAFFRON, player_rect)
        modi_text = font.render("MODI", True, BLACK)
        screen.blit(modi_text, (player_rect.x + 5, player_rect.y + 25))
    
    # Draw Items (Coins and Obstacles)
    for item in items:
        if item["type"] == "coin":
            pygame.draw.circle(screen, BLACK, (item["lane"] * LANE_WIDTH + LANE_WIDTH // 2, int(item["y"])), 15)
        else:
            pygame.draw.rect(screen, RED, (item["lane"] * LANE_WIDTH + 20, item["y"], LANE_WIDTH - 40, 30))

    # Draw Score
    score_display = font.render(f"Black Coins: {score}", True, BLACK)
    screen.blit(score_display, (10, 10))

    if game_over:
        msg = font.render("CAUGHT BY STUDENTS! Press Space to Restart", True, RED)
        screen.blit(msg, (SCREEN_WIDTH // 2 - 180, SCREEN_HEIGHT // 2))
        keys = pygame.key.get_pressed()
        if keys[pygame.K_SPACE]:
            game_over = False
            score = 0
            items = []
            player_lane = 1

    pygame.display.flip()
    clock.tick(FPS)

pygame.quit()