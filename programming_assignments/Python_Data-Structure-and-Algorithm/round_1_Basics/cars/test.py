import cars


def main():
    minun_fiat = cars.Car(5.0, "ZZZ-123")
    naapurin_ferrari = cars.Car(12.5, "ITA-1")

    print(minun_fiat.drive(20))
    print(minun_fiat.refuel(10))

    print(naapurin_ferrari.drive(450))

main()