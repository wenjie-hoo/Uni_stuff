
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import random
from collections import deque

class SnakeGame:
    def __init__(self, grid_size=10):
        self.GRID_SIZE = grid_size
        self.grid = np.zeros((grid_size, grid_size))
        self.snake = deque([(0, 0)])
        self.place_random_squares()

        # Set up the figure and axis
        self.fig, self.ax = plt.subplots()
        self.im = self.ax.matshow(self.grid,  vmin=0, vmax=2)
        self.ax.set_xticks([])
        self.ax.set_yticks([])
        self.snake_squares = []


    def place_random_squares(self):
        for _ in range(10):  
            x, y = random.randint(0, self.GRID_SIZE - 1), random.randint(0, self.GRID_SIZE - 1)
            while self.grid[x, y] == 1: 
                x, y = random.randint(0, self.GRID_SIZE - 1), random.randint(0, self.GRID_SIZE - 1)
            self.grid[x, y] = 1

    # def update(self,_):
    #     self.update_game()
    #     self.update_snake_squares()
    #     self.im.set_array(self.grid)
    #     return [self.im] + self.snake_squares
    
    def update(self, _):
        self.update_game()
        self.update_snake_squares()
        self.im.set_array(self.grid)
        return [self.im] + self.snake_squares if self.snake_squares else [self.im]


    def check_collision(self):
        head = self.snake[0]
        if not (0 <= head[0] < self.GRID_SIZE and 0 <= head[1] < self.GRID_SIZE):
            return True
        print(f'head:{head}') 
        print(self.snake)
        if head in list(self.snake)[0:] or self.grid[head[0], head[1]] == 1:
            return True
        return False

    def update_game(self):
        head = self.snake[0]
        direction = random.choice(['UP', 'DOWN', 'LEFT', 'RIGHT'])
        if direction == 'UP':
            new_head = (head[0] - 1, head[1])
        elif direction == 'DOWN':
            new_head = (head[0] + 1, head[1])
        elif direction == 'LEFT':
            new_head = (head[0], head[1] - 1)
        elif direction == 'RIGHT':
            new_head = (head[0], head[1] + 1)
        if 0 <= new_head[0] < self.GRID_SIZE and 0 <= new_head[1] < self.GRID_SIZE:
            self.snake.appendleft(new_head)
            if not self.grid[new_head[0], new_head[1]] == 1:
                tail = self.snake.pop()
                self.grid[tail[0], tail[1]] = 0
            else:
                x, y = random.randint(0, self.GRID_SIZE - 1), random.randint(0, self.GRID_SIZE - 1)
                while self.grid[x, y] == 1: 
                    x, y = random.randint(0, self.GRID_SIZE - 1), random.randint(0, self.GRID_SIZE - 1)
                self.grid[x, y] = 1
        else:
            self.game_over()
            
    def update_snake_squares(self):
        for square in self.snake_squares:
            square.remove()
        self.snake_squares = []
        if not self.check_collision():
            print("colliding with itself")
        else:
            for i, segment in enumerate(self.snake):
                x, y = segment
                facecolor = 'red' if i == 0 else 'green'
                square = plt.Rectangle((y - 0.5, x - 0.5), 1, 1, facecolor=facecolor, edgecolor='black')
                self.snake_squares.append(square)
                self.ax.add_patch(square)

                
    def game_over(self):
        print("Game Over!")

    def play(self):
        ani = animation.FuncAnimation(self.fig, self.update, frames=500, repeat=False, blit=True, interval=5000)
        plt.show()

if __name__ == "__main__":
    game = SnakeGame(grid_size=10)
    game.play()