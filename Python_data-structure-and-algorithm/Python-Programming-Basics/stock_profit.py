sell=float(input("Milla hinnalla osakkeet myytiin (eur / kpl)?\n"))
amount=float(input("Montako osaketta myytiin?\n"))
time=float(input("Montako kuukautta omistit osakkeet?\n"))
selling= sell*amount
purchase=14.3*amount+2.25*time+9.5
if selling>=purchase:
	income=selling-purchase-9.5
	print("Sait osakkeista voittoa",income,"euroa.")
else:
	income=purchase-selling-9.5
	print("Sait osakkeista voittoa",income,"euroa.")
	