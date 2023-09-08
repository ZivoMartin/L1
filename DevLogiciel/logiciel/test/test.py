from random import randint
from logiciel.src.models.points import point
from logiciel.src.models.FileRepo import FileRepo

def liste_points():
    pts = [0]*10
    for i in range(10):
        Point = point(randint(-100, 100), randint(-100, 100), randint(0, 60))
        pts[i] = (Point.x, Point.y)
    return pts

def liste_temps():
    tmps = [0]*10
    for i in range(10):
        Point = point(randint(-100, 100), randint(-100, 100), randint(0, 60))
        tmps[i] = Point.timer
    return tmps

print(liste_points(), liste_temps())
fichier = FileRepo(liste_points(), liste_temps())
fichier.transform2csv("points.csv", "C:/Users/zivom/OneDrive/Bureau/DevLogiciel/logiciel/Data")



