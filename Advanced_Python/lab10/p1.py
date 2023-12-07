import numpy as np
import random
from matplotlib import pyplot as plt, patches
from matplotlib import animation
from collections import deque

class SnakeGame:
    def __init__(self, grid_size=10):
        self.GRID_SIZE = grid_size
        self.grid = np.zeros((grid_size, grid_size))
        self.snake = deque([(0, 0)])
        self.direction = 'RIGHT'  # init dire
        self.place_random_squares()

        self.fig, self.ax = plt.subplots()
        self.im = self.ax.matshow(self.grid, vmin=0, vmax=2)
        self.ax.set_xticks([])
        self.ax.set_yticks([])
        self.snake_squares = []

    def place_random_squares(self):
        for _ in range(10):
            self.place_random_square()
            
    def place_random_square(self):
        x, y = self.get_random_empty_location()
        self.grid[x, y] = 1

    def get_random_empty_location(self):
        x, y = random.randint(0, self.GRID_SIZE - 1), random.randint(0, self.GRID_SIZE - 1)
        while self.grid[x, y] == 1:
            x, y = random.randint(0, self.GRID_SIZE - 1), random.randint(0, self.GRID_SIZE - 1)
        return x, y

    def update(self, _):
        self.update_game()
        self.update_snake_squares()
        self.im.set_array(self.grid)
        return [self.im] + self.snake_squares if self.snake_squares else [self.im]

    def check_collision(self):
        head = self.snake[0]
        return not (0 <= head[0] < self.GRID_SIZE and 0 <= head[1] < self.GRID_SIZE) or head in list(self.snake)[1:] or self.grid[head[0], head[1]] == 1

    def update_game(self):
        head = self.snake[0]
        possible_directions = ['UP', 'DOWN', 'LEFT', 'RIGHT']
        self.direction = random.choice(possible_directions)

        if self.check_collision():
            print("Colliding with itself")
            if infinity_fun==False:
                self.game_over()
                return

        new_head = self.calculate_new_head(head)

        if self.is_inside_grid(new_head):
            self.snake.appendleft(new_head)
            if not self.grid[new_head[0], new_head[1]] == 1:
                self.remove_tail()
            else:
                self.place_random_square()
        else:
            self.game_over()

    def calculate_new_head(self, head):
        if self.direction == 'UP':
            return (head[0] - 1, head[1])
        elif self.direction == 'DOWN':
            return (head[0] + 1, head[1])
        elif self.direction == 'LEFT':
            return (head[0], head[1] - 1)
        elif self.direction == 'RIGHT':
            return (head[0], head[1] + 1)

    def is_inside_grid(self, position):
        return 0 <= position[0] < self.GRID_SIZE and 0 <= position[1] < self.GRID_SIZE

    def remove_tail(self):
        tail = self.snake.pop()
        self.grid[tail[0], tail[1]] = 0

    def update_snake_squares(self):
        for square in self.snake_squares:
            square.remove()

        self.snake_squares = []
        for i, segment in enumerate(self.snake):
            x, y = segment
            facecolor = 'red' if i == 0 else 'green'
            square = plt.Rectangle((y - 0.5, x - 0.5), 1, 1, facecolor=facecolor, edgecolor='black')
            self.snake_squares.append(square)
            self.ax.add_patch(square)

    def game_over(self):
        print("Game Over!")

    def play(self):
        _ = animation.FuncAnimation(self.fig, self.update, frames=500, repeat=False, blit=True, interval=100)
        plt.show()

if __name__ == "__main__":
    infinity_fun = True
    game = SnakeGame(grid_size=10)
    game.play()
