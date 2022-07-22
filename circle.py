from math import sin

WIDTH = 120
HEIGHT = 30

def createScreen():
    screen = [" " for x in range(HEIGHT*WIDTH+1)]
    screen[WIDTH*HEIGHT] = "\n"
    return screen


def circle(n, screen, symbol):
    if screen is None:
        print("Error")
    else:
        pixAspect = 10 / 28
        for i in range(HEIGHT):
            for j in range(WIDTH):
                y = i-HEIGHT/2
                x = j-WIDTH/2
                x *= pixAspect
                if x*x + y*y <= n*n: screen[j + i * WIDTH] = symbol
                if i == HEIGHT/2 and j == WIDTH/2: screen[j + i * WIDTH] = "O"

# n is size direct line
# symbol from drawing line
# coordnate is or
def directLine(n, screen, orientation):
    if screen is None:
        print("Error! We haven't screen")
    else:
        if orientation.lower() != "x" and orientation.lower() != "y":
            print("Error. We haven't a orientation")
        else:
            for i in range(HEIGHT):
                for j in range(WIDTH):
                    if orientation == "y":
                        if j == WIDTH/2 and HEIGHT / 2 + n > i > HEIGHT / 2 - n: screen[j + i * WIDTH] = "║"
                    else:
                        if i == HEIGHT/2 and WIDTH / 2 + n > j > WIDTH / 2 - n: screen[j + i * WIDTH] = "═"


def drowAim(n, screen):
    directLine(n*3-5, screen, "x")
    directLine(n, screen, "y")
    screen[int(WIDTH/2 + HEIGHT/2 * WIDTH)] = "╬"

def printList(screen):
    for i, elem in enumerate(screen):
        if i % WIDTH == 0:
            print()
        else:
            print(elem, end="")

if __name__ == '__main__':
    screen = createScreen()
    circle(10, screen, "#")
    circle(6, screen, "@")
    circle(4, screen, " ")
    circle(2, screen, "I")
    drowAim(12, screen)
    printList(screen)
