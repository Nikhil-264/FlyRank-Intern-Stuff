#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants for the game
const int SIZE = 10;
const int MINES = 10;
const int TILE_SIZE = 32;
const int WINDOW_SIZE = SIZE * TILE_SIZE;

vector<vector<int>> mines(SIZE, vector<int>(SIZE, 0));
vector<vector<bool>> revealed(SIZE, vector<bool>(SIZE, false));
vector<vector<bool>> flagged(SIZE, vector<bool>(SIZE, false));

// Function to place mines on the board
void placeMines() {
    srand(time(0));
    int count = 0;
    while (count < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (mines[x][y] == 0) {
            mines[x][y] = -1;  // -1 represents a mine
            count++;
        }
    }
}

// Function to calculate numbers around mines
void calculateNumbers() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (mines[i][j] == -1) continue;
            int count = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && mines[ni][nj] == -1) {
                        count++;
                    }
                }
            }
            mines[i][j] = count;
        }
    }
}

// Function to uncover a cell
void uncover(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || revealed[x][y]) return;

    revealed[x][y] = true;

    if (mines[x][y] == 0) {
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                uncover(x + di, y + dj);
            }
        }
    }
}

// Function to check if the player has won
bool isWin() {
    int uncoveredCount = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (revealed[i][j]) uncoveredCount++;
        }
    }
    return uncoveredCount == SIZE * SIZE - MINES;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Minesweeper");

    sf::Texture tileTexture, mineTexture, flagTexture;
    tileTexture.loadFromFile("images/tile.png");
    mineTexture.loadFromFile("images/mine.png");
    flagTexture.loadFromFile("images/flag.png");

    sf::Sprite tileSprite(tileTexture), mineSprite(mineTexture), flagSprite(flagTexture);

    placeMines();
    calculateNumbers();

    bool gameOver = false;

    while (window.isOpen()) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int x = pos.x / TILE_SIZE;
        int y = pos.y / TILE_SIZE;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (!gameOver && x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                        if (mines[x][y] == -1) {
                            gameOver = true;
                        } else {
                            uncover(x, y);
                        }
                    }
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    if (!gameOver && x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                        flagged[x][y] = !flagged[x][y];
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                tileSprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);
                flagSprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);
                mineSprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);

                if (revealed[i][j]) {
                    if (mines[i][j] == -1) {
                        window.draw(mineSprite);
                    } else {
                        sf::Font font;
                        font.loadFromFile("fonts/arial.ttf");

                        sf::Text number;
                        number.setFont(font);
                        number.setCharacterSize(20);
                        number.setFillColor(sf::Color::Black);
                        number.setString(to_string(mines[i][j]));
                        number.setPosition(i * TILE_SIZE + 8, j * TILE_SIZE + 4);
                        window.draw(number);
                    }
                } else {
                    window.draw(tileSprite);
                    if (flagged[i][j]) {
                        window.draw(flagSprite);
                    }
                }
            }
        }

        if (isWin()) {
            sf::Font font;
            font.loadFromFile("fonts/arial.ttf");

            sf::Text winText;
            winText.setFont(font);
            winText.setCharacterSize(50);
            winText.setFillColor(sf::Color::Green);
            winText.setString("You Win!");
            winText.setPosition(100, WINDOW_SIZE / 2 - 25);
            window.draw(winText);
        }

        window.display();
    }
    return 0;
}
