weight = float(input("Mika on painosi (kg)?\n"))
quantity = float(input("Montako alkoholiannosta olet nauttinut?\n"))
alcohol = quantity*12
percent = alcohol/(weight*0.7)
print("Veren alkoholipitoisuus on", percent, "promillea.")
if percent >= 0.5:
    print("Alkoholipitoisuus ylittaa rattijuopumusrajan.")
else:
    print("Alkoholipitoisuus ei ylita rattijuopumusrajaa.")
