import random

# Rastgele matris olusturulur.
matris = [[random.randint(-99, 99) for j in range(10)] for i in range(10)]
for i in range(10):
    for j in range(10):
        print(matris[i][j], end="\t")
    print()

# Yatayda ve dikeyde toplamlar hesaplanir.
max_yatay_toplam = -999
yatay_satir, yatay_sutun = 0, 0
min_dikey_toplam = 999
dikey_satir, dikey_sutun = 0, 0
for i in range(10):
    for j in range(8):
        yatay_toplam = sum(matris[i][j:j+3])
        if yatay_toplam > max_yatay_toplam:
            max_yatay_toplam = yatay_toplam
            yatay_satir, yatay_sutun = i, j
for i in range(8):
    for j in range(10):
        dikey_toplam = matris[i][j] + matris[i+1][j] + matris[i+2][j]
        if dikey_toplam < min_dikey_toplam:
            min_dikey_toplam = dikey_toplam
            dikey_satir, dikey_sutun = i, j

# Sonuclar mutlak degerli olarak kiyaslanir ve kazanan belirlenir.
yatay_abs = abs(max_yatay_toplam)
dikey_abs = abs(min_dikey_toplam)
if yatay_abs > dikey_abs:
    print(f"\nMelih kazandi! Yatayda {matris[yatay_satir][yatay_sutun]}, " +
          f"{matris[yatay_satir][yatay_sutun+1]}, {matris[yatay_satir][yatay_sutun+2]} " +
          "sayilarinin toplami en buyuk.")
elif yatay_abs < dikey_abs:
    print(f"\nMubariz kazandi! Dikeyde {matris[dikey_satir][dikey_sutun]}, " +
          f"{matris[dikey_satir+1][dikey_sutun]}, {matris[dikey_satir+2][dikey_sutun]} " +
          "sayilarinin toplami en kucuk.")
else:
    print(f"\nBerabere kaldiniz! Yatayda {matris[yatay_satir][yatay_sutun]}, " +
          f"{matris[yatay_satir][yatay_sutun+1]}, {matris[yatay_satir][yatay_sutun+2]} " +
          f"sayilarinin toplami dikeyde {matris[dikey_satir][dikey_sutun]}, " +
          f"{matris[dikey_satir+1][dikey_sutun]}, {matris[dikey_satir+2][dikey_sutun]} " +
          "sayilarinin toplamina esit.")
