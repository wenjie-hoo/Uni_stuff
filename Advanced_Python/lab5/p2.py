from itertools import product

class Formula:
    def __disjunction__(self, f2):
        return Or(self, f2)
    def __conjunction__(self, f2):
        return And(self, f2) 
    
    def tautology(self):
        if self.is_tautology is not None:
            return self.is_tautology
        for vals in product((0, 1), repeat=len(self.vars)):
            if not self.evaluate(dict(zip(self.vars, vals))):  
                self.is_tautology = False
                return False
        self.is_tautology = True
        return True

class BinaryOperation(Formula):
    def __init__(self, f1, f2):
        self.f1 = f1
        self.f2 = f2
        self.vars = f1.vars + f2.vars
        self.is_tautology = None
    def __str__(self):
        return f'({str(self.f1)} {self.op} {str(self.f2)})'

class Implication(BinaryOperation):
    def evaluate(self, vars):
        if self.f1.evaluate(vars):
            return True
        else: 
            return self.f2.evaluate(vars)
            
    def __str__(self):
        return f'({str(self.f1)} → {str(self.f2)})'
 
class Or(BinaryOperation):
    op = '∨'
    def evaluate(self, vars):
        if self.f1.evaluate(vars):
            return True
        else: 
            return self.f2.evaluate(vars)

class And(BinaryOperation):
    op = '∧'
    def evaluate(self, vars):
        if not self.f1.evaluate(vars):
            return False
        else: 
            return self.f2.evaluate(vars)

class Not(Formula):
    def __init__(self, f1):
        self.f1 = f1
        self.vars = f1.vars
        self.is_tautology = None

    def evaluate(self, vars):
        return not self.f1.evaluate(vars)

    def __str__(self):
        return "¬" + str(self.f1)

class Var(Formula):
    def __init__(self, name):
        self.vars = [name]
        self.is_tautology = False

    def evaluate(self, vars):
        return vars[self.vars[0]]

    def __str__(self):
        return self.vars[0]

class Const(Formula):
    def __init__(self, val):
        self.val = val
        self.vars = []
        self.is_tautology = True if val else False

    def evaluate(self, vars):
        return self.val

    def __str__(self):
        return '⊤' if self.val else '⊥'


print(Implication(Const(True), Const(False)))
print(Implication(Const(False), Const(False)))

print(Or(Not(Var("A")), And(Var("B"), Const(True))))
print(Or(Not(Var('A')), Var('A')).tautology())
print(Or(Not(Var('A')), Var('B')).tautology())


print(And(Var('A'), Not(Var('A'))))
print(Or(Not(Var("A")), And(Var("B"), Const(True))))

print(Not(Or(Var('A'),Var('B')))) 
print(And(Not(Var('A')),Not(Var('B'))))