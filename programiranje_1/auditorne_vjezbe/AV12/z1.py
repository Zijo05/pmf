def pretraga_po_imenu(imenik, ime):
    for ime_prezime in imenik:
        broj_telefona = imenik[ime_prezime]
        samo_ime = ime_prezime.split(" ")[0]

        if ime == samo_ime:
            print(f"{ime_prezime}: {broj_telefona}")

def pretraga_po_broju(imenik, trazeni_broj):
    for ime_prezime in imenik:
        broj_telefona = imenik[ime_prezime]

        if broj_telefona == trazeni_broj:
            print(f"Osoba sa brojem telefona {trazeni_broj}: {ime_prezime}")
            return

    print("Ne postoji osoba sa trazenim brojem telefona u imeniku!")

def izbrisi_po_imenu(imenik, ime_prezime):
    if ime_prezime not in imenik:
        print(f"Osoba {ime_prezime} ne postoji u imeniku!")
    else:
        del imenik[ime_prezime]
        print(f"Osoba {ime_prezime} izbrisana iz imenika!")


imenik = {
    "Adisa Bolic": "061123456",
    "Adisa Polic": "062436432",
    "Niko Nesto": "061877876",
    "Niko Nikic": "063221235",
    "Amir Pehlic": "061123455"
}

pretraga_po_imenu(imenik, "Adisa")
pretraga_po_imenu(imenik, "Amir")


pretraga_po_broju(imenik, "061877876")
pretraga_po_broju(imenik, "066212231")

izbrisi_po_imenu(imenik, "Niko Nikic")
print(imenik)

izbrisi_po_imenu(imenik, "Ne postoji")
