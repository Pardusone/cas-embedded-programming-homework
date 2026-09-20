import numpy as np
import time

poolMap = np.zeros((20, 20), dtype=int)
coordinates = np.zeros((5, 2), dtype=int)

poolMap[5][5] = 1  # BAŞLANGIÇ
poolMap[12][7] = 2  # 1.HEDEF
poolMap[8][13] = 2  # 2.HEDEF
poolMap[10][15] = 2  # 3.HEDEF
poolMap[15][11] = 2  # 4.HEDEF

coordinates[0] = [5, 5]  # BAŞLANGIÇ
coordinates[1] = [12, 7]  # 1.HEDEF
coordinates[2] = [8, 13]  # 2.HEDEF
coordinates[3] = [10, 15]  # 3.HEDEF
coordinates[4] = [15, 11]  # 4.HEDEF

araba_pozisyonu = coordinates[0]  
skor = 0  

def uzunluk_hesaplayici(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

while len(coordinates) > 1:
    min_mesafe = float('inf')  
    siradaki_hedef = None

    for i in range(1, len(coordinates)):
        hedef = coordinates[i]
        distance = uzunluk_hesaplayici(araba_pozisyonu, hedef) 

        if distance < min_mesafe:
            min_mesafe = distance
            siradaki_hedef = hedef

    hedefe_uzaklik = uzunluk_hesaplayici(araba_pozisyonu, siradaki_hedef)
    skor -= hedefe_uzaklik 

    araba_pozisyonu = siradaki_hedef  

    skor += 15  

    coordinates = np.delete(coordinates, np.where((coordinates == siradaki_hedef).all(axis=1)), axis=0)

print("Araç puanı:", skor)