# to help with Advent day 12, visualize the outputs better
fin = open("out7","r")
lns = fin.readlines()
fin.close()
from turtle import *
penup()
speed(0)
# set size
input("enter to start")
screensize(1920,1080)
offset = 900
layer = 0
for i in range(len(lns)):
    for j in range(len(lns[0])):
        if lns[i][j] in "#*^O":
            goto(i-offset,j + layer * 200)
            pendown()
        # lower if range is too high
        if (i-offset > 1920):
            offset += 1920
            layer+=1
input("enter when done")