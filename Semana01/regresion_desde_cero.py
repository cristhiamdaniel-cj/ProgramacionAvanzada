import random

def gradiente_regression(X,y,alpha,b,w):
    dw = 0.0
    db = 0.0
    for i in range(len(X)):
        aux = -2.0*(y[i]-(w*X[i]+b))
        db = db + aux
        dw = dw + aux*X[i]
    aux = 1.0/float(len(X))
    b = b - aux*alpha*db
    w = w - aux*alpha*dw
    return b,w

    pass

def model(X,y,alpha,b,w,epochs):
    
    for e in range(epochs):
        b,w = gradiente_regression(X,y,alpha,b,w)
        if e%100==0:
            print("Epoch: ",e," Loss: ",loss(X,y,b,w))
    return b,w

def prediction(x,b,w):
    return (w*x)+b

def loss(X,y,b,w):
    sum = 0
    for i in range(len(X)):
        sum = sum + (y[i]-(w*X[i]+b))**2
    return sum/float(len(X))

def create_sample(n):
    y = []
    X = list(range(n))
    for i in range(len(X)):
        y.append(20+X[i]+random.random()*20) # ruido aleatorio
    return X,y

def plot(fig, X, y, b, w, epochs):
    pass

def main():
    X = [1,2,3,4,5]
    y = [5.3,7.9,9.5,11.1,13.8]

    epochs = 9001
    alpha = 0.01
    b = 0.0
    w = 0.0

    b, w = model(X,y,alpha,b,w,epochs)
    print("b: ",b," w: ",w)
    print("Loss: ",loss(X,y,b,w))
    print("Prediccion: ",prediction(6,b,w))


if __name__ == "__main__":
    main()