print("Apostrof \'. Navodnik \". Kosa crta \\")

a = 10
b = 3
zbir = a+b
print(f"Zbir je {zbir}. Razlika je {a-b}.")

# broj decimala
print(f"Kolicnik je {a / b:.3f} na tri decimale. {a / b:.5f} na 5 decimala")

# zarezi i broj decimala
print(f"Veliki broj {1000000.12345:,.2f}.")

# postotak
print(f"Postotak {0.3:.2%}")

# width
print(f"Zbir je {123:5}")

# alignment <, >, ^
print(f"Zbir je {123:<5}")
print(f"Zbir je {123:>5}")
print(f"Zbir je {123:^5}")