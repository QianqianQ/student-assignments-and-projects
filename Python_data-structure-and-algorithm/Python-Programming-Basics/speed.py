import math
def laske_huippunopeus(kierrosnopeus, renkaan_halkaisija):
    length=math.pi*(renkaan_halkaisija/1000)
    speed=length*(kierrosnopeus/1000)
    return speed
def laske_kierrosnopeus(moottorin_kv_arvo, akun_jannite):
    speed_min=moottorin_kv_arvo*akun_jannite
    speed_sec=(speed_min/60)
    return speed_sec
def muuta_nopeus(nopeus_ms):
    change=nopeus_ms*3.6
    return change

if __name__ == '__main__':
    print("Ohjelma laskee harjattomalla moottorilla\nvarustetun ajoneuvon huippunopeuden.")
    battery=int(input("Anna akun jannite (V).\n"))
    jannite = int(input("Anna moottorin kv-arvo (rpm/V).\n"))
    diameter=int(input("Anna renkaan halkaisija (mm).\n"))
    a=laske_kierrosnopeus(jannite,battery)
    speed_m_s=laske_huippunopeus(a*1000,diameter)
    speed_km_h=muuta_nopeus(speed_m_s)
    print("Ajoneuvon teoreettinen huippunopeus\non","%.1f"%(speed_m_s),"m/s ja", "%.1f"%(speed_km_h),"km/h.")
















