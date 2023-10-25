from decimal import Decimal

def vat_invoice(list):
    return sum(list)*0.23

def vat_receipt(list):
    return sum([x*0.23 for x in list])

def vat_invoice_dec(list):
    list = [Decimal(str(x)) for x in list]
    return sum(list)*Decimal('0.23')

def vat_receipt_dec(list):
    list = [Decimal(str(x))*Decimal('0.23') for x in list]
    return sum(list)


if __name__ == "__main__":
    shopping = [4, 43, 22, 23, 345]
    shopping_f = [0.24, 4.5, 13.59, 123.65]
    
    print(vat_invoice(shopping) == vat_receipt(shopping))
    print(vat_invoice(shopping_f) == vat_receipt(shopping_f))
    # 12.12000000000000001
    print(vat_invoice_dec(shopping) == vat_receipt_dec(shopping))
    print(vat_invoice_dec(shopping_f) == vat_receipt_dec(shopping_f))