normalprice = float(input("Mika on puheluiden normaali minuuttihinta (snt)?\n"))
package200 = float(input("Mika on Pulinapaketti200:n hinta (eur)?\n"))
package1500 = float(input("Mika on Pulinapaketti1500:n hinta (eur)?\n"))
minutes = float(input("Montako minuuttia puhut kuukaudessa?\n"))
if minutes<=200:
    a = (normalprice * minutes) / 100
    b=package200
    c=package1500
elif minutes>=1500:
    a = (normalprice * minutes) / 100
    b = package200 + (normalprice * (minutes - 200)) / 100
    c = package1500 + (normalprice * (minutes - 1500))/100
else:
    a = (normalprice * minutes) / 100
    b= package200 + (normalprice * (minutes - 200)) / 100
    c = package1500
if a == b == c:
    print("Kannattaa hankkia Pulinapaketti1500.")
    print("Puhelut maksavat kuukaudessa", a, "euroa.")
elif a == b and a < c:
    print("Kannattaa hankkia Pulinapaketti200.")
    print("Puhelut maksavat kuukaudessa", b, "euroa.")
elif a == c and a < b:
    print("Kannattaa hankkia Pulinapaketti1500.")
    print("Puhelut maksavat kuukaudessa", c, "euroa.")
elif b == c and b < a:
    print("Kannattaa hankkia Pulinapaketti1500.")
    print("Puhelut maksavat kuukaudessa", c, "euroa.")
elif a < b and a < c:
    print("Pulinapaketin hankkiminen ei kannata.")
    print("Puhelut maksavat kuukaudessa", a, "euroa.")
elif b < a and b < c:
    print("Kannattaa hankkia Pulinapaketti200.")
    print("Puhelut maksavat kuukaudessa", b, "euroa.")
elif c < a and c < b:
    print("Kannattaa hankkia Pulinapaketti1500.")
    print("Puhelut maksavat kuukaudessa", c, "euroa.")

