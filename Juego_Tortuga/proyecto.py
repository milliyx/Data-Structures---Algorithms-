import turtle #Importamos la libreria de graficos
import json #Importamos la libreria de json
import time #Importa la libreria de tiempo
from turtle import * #Importa la parte de la libreria que nos ayudará con el movimiento (del ratón) por teclas

def pasosDir(direccion,cantidad): #Halla la menor cantidad de pasos posible al avanzar una casilla en cualquiera de las direcciones
    for i in range(len(cantidad)): #Según cada elemento:
        if cantidad[i][0] == direccion: #Dependiendo de la dirección del movimiento:
            return cantidad[i][1] #Retorna la cantidad de pasos que requiere moverse en esa dirección

def up(): #Declara la dirección y el movimiento del ratón hacia arriba
    turtle.setheading(90) #Hace que el ratón apunte hacia arriba
    turtle.forward(24) #Mueve al ratón una casilla adelante
def down(): #Declara la dirección y el movimiento de la tortuga hacia abajo
    turtle.setheading(270) #Hace que el ratón apunte hacia abajo
    turtle.forward(24) #Mueve al ratón una casilla atrás
def left(): #Declara la dirección y el movimiento de la tortuga hacia la izquierda
    turtle.setheading(180) #Hace que el ratón apunte hacia la izquierda
    turtle.forward(24) #Mueve al ratón una casilla la izquierda
def right(): #Declara la dirección y el movimiento de la tortuga hacia la derecha
    turtle.setheading(0) #Hace que el ratón apunte hacia la derecha
    turtle.forward(24) #Mueve al ratón una casilla hacia la derecha

def json_py(archivo_json): #La funcion nos dara la matriz que representara al laberinto
    with open(archivo_json) as contenido: #Abriendo el archivo de tipo json
        cursos = json.load(contenido) #Asigna a la variable el arreglo
    nivel = []
    for a in cursos: #Segpun cada elemento del arreglo:
        nivel.append(f"{a['Fila']}") #Añade a un nuevo arreglo solo los valores que corresponden a las casillas del labei¿rinto
    return nivel #Retorna el arreglo que representa el laberinto

class Pen(turtle.Turtle): #Permite colorear y definir la forma de las casillas del mapa del laberinto
    def __init__(self): #Define y abrevia el lapiz
        turtle.Turtle.__init__(self) #Inicia la función turtle para definir al lápiz
        self.shape("square") #Establece la forma con la que pintara la casilla
        self.color("white") #Establece el color con que pintara la casilla
        self.penup() #Alza el lapiz, que significa que el lapiz ya no se utilizara por el momento
        self.speed(0) #Establece la velocidad con que pinta la casilla en cuestión
        
class Pen1(turtle.Turtle): #Permite colorear y definir la forma de las casillas del mapa del laberinto
    def __init__(self): #Define y abrevia el lapiz
        turtle.Turtle.__init__(self) #Inicia la función turtle para definir al lápiz
        self.shape("square") #Establece la forma con la que pintara la casilla
        self.color("brown") #Establece el color con que pintara la casilla
        self.penup() #Alza el lapiz, que significa que el lapiz ya no se utilizara por el momento
        self.speed(0) #Establece la velocidad con que pinta la casilla en cuestión
        
class Pen2(turtle.Turtle): #Permite colorear y definir la forma de las casillas del mapa del laberinto
    def __init__(self): #Define y abrevia el lapiz
        turtle.Turtle.__init__(self) #Inicia la función turtle para definir al lápiz
        self.shape("circle") #Establece la forma con la que pintara la casilla
        self.color("blue") #Establece el color con que pintara la casilla
        self.penup() #Alza el lapiz, que significa que el lapiz ya no se utilizara por el momento
        self.speed(0) #Establece la velocidad con que pinta la casilla en cuestión

class Pen3(turtle.Turtle): #Permite colorear y definir la forma de las casillas del mapa del laberinto
    def __init__(self): #Define y abrevia el lapiz
        turtle.Turtle.__init__(self) #Inicia la función turtle para definir al lápiz
        self.shape("circle") #Establece la forma con la que pintara la casilla
        self.color("red") #Establece el color con que pintara la casilla
        self.penup() #Alza el lapiz, que significa que el lapiz ya no se utilizara por el momento
        self.speed(0) #Establece la velocidad con que pinta la casilla en cuestión

class Turtle(turtle.Turtle): #Permite colorear y definir la forma de las casillas del mapa del laberinto
    def __init__(self): #Define y abrevia el lapiz
        turtle.Turtle.__init__(self) #Inicia la función turtle para definir al lápiz
        self.pendown() #Baja el lapiz, que significa que el lapiz se utilizara en ese momento
        self.shape("turtle") #Establece la forma con la que pintara la casilla
        self.color("green") #Establece el color con que pintara la casilla
        self.penup() #Alza el lapiz, que significa que el lapiz ya no se utilizara por el momento
        self.speed(0) #Establece la velocidad con que pinta la casilla en cuestión

def siguienteMovimiento(x,y): #Devuelve las coordenadas de los movimientos en las cuatro direcciones
    return { #Retorna:
        'left':  [x-1,y], #Coordenada nueva en direccion hacia la izquierda
        'right': [x+1,y], #Coordenada nueva en direccion hacia la derecha
        'up':  [x,y-1], #Coordenada nueva en direccion hacia arriba
        'down':  [x,y+1] #Coordenada nueva en direccion hacia abajo
    }.values() #Devuelve las 4 coordenadas al mismo tiempo

def mov(rutaCorta): #Determina los movimientos que debe emplear en el inciso b
    movimientos = [] 
    for i in range(len(rutaCorta)-1): #Agrupando pares consecutivos:
        if rutaCorta[i+1][0] > rutaCorta[i][0]: #Si la coordenada actual es mayor a su antecesora en el eje x:
            movimientos.append('R') #El movimiento es hacia la derecha
        if rutaCorta[i+1][0] < rutaCorta[i][0]: #Si la coordenada actual es menor a su antecesora en el eje x:
            movimientos.append('L') #El movimiento es hacia la izquierda
        if rutaCorta[i+1][1] > rutaCorta[i][1]: #Si la coordenada actual es mayor a su antecesora en el eje y:
            movimientos.append('D') #El movimiento es hacia la abajo
        if rutaCorta[i+1][1] < rutaCorta[i][1]: #Si la coordenada actual es menor a su antecesora en el eje y:
            movimientos.append('U') #El movimiento es hacia la arriba
    return movimientos #Retorna el arreglo de movimientos

def mejorRuta(nivel,inicio,largoNivel,altoNivel,queso,pared): #Define la ruta con menor cantidad de pasos
    buscaCaminos = [[inicio]] #IEstablece la primera coordenada 
    
    while buscaCaminos != []: #Para iniciar el condicional:
        rutaActual = buscaCaminos.pop(0) #Elimina la ruta incial, que derivara en otras provinientes de esa
        posicion = rutaActual[-1] #Agarra la ultima posicion o coordenada dentro del conjunto de rutas
        
        x, y = posicion #Establece dos variables con el valor de las coordenadas de la posición actual
        
        if nivel[y][x] == queso: #Si la posición de llegada es igual a la posición actual:
            return rutaActual #Retorna la ruta que sería la más corta en pasos
        
        for siguiente in siguienteMovimiento(x, y): #Establece todas las posibles coordenadas a las que se movería según cada dirección
            x1, y1 = siguiente #Establece dos variables con el valor de las coordenadas de la posición siguiente
            
            if x1 < 0 or x1 >= largoNivel: #Si la posicion siguiente respecto al eje x esta fuera de rango:
                continue #Continua el condicional
            
            if y1 < 0 or y1 >= altoNivel: #Si la posicion siguiente respecto al eje y esta fuera de rango:
                continue #Continua el condicional
            
            if nivel[y1][x1] == pared: #Si la posicion contiene un bloque de la pared:
                continue #Continua el condicional
            
            buscaCaminos.append(rutaActual + [siguiente]) #Añade a la ruta la coordenada que seguiria para su movimiento

def pasosMovimiento(nivel,inicio,score,cantidadPasos,ratoncito,queso): #Permitirá mover el ratón en la dirección que se guste:
    pen = Pen() #Usara el lápiz para ir anotando la vida restante en cada etapa del movimiento
        
    pen.penup() #Levanta el lápiz
    pen.hideturtle() #Esconde su forma
    pen.goto(80,-50) #Se dirije un poco abajo del laberinto
    pen.write("Vidas restantes: 100", align = "center", font = ("Arial", 15, "normal")) #Escribe la cantidad de la vida
    
    turtle.shape("turtle") #Declara la forma del "ratón"
    turtle.color("green") #Declara el color del ratón
    turtle.penup() #Levanta al ratón
    turtle.clearstamp(turtle.position()) #Limpia la casilla donde estuvo el ratón
    for fila in range(len(nivel)): #Según cada fila:
        for columna in range(len(nivel[fila])): #Según cada columna
            if nivel[fila][columna] == ratoncito: #La posicion inicial del ratón:
                turtle.goto(columna*24,(len(nivel[fila])-1-fila)*24) #Dirije al raton a esa posición inicial
                b = turtle.stamp() #Muestra al ratón en esa posición inicial
    
    pen.clear() #Borralo escrito por el lapiz
    pen.write("Vidas restantes: {}".format(score), align = "center", font = ("Arial", 15, "normal")) #Escribe la vida inicial
    
    paso1 = 0
    paso2 = 0
    #Determina el movimiento respecto al orígen y a su posición inicial del laberinto
    if turtle.xcor() > inicio[1]: #Si la coordenada esta a la izquierda:
        paso1 = pasosDir("L",cantidadPasos) #Devuelve los pasos que toma ir a la izquierda
    if turtle.xcor() < inicio[1]: #Si la coordenada esta a la derecha:
        paso1 = pasosDir("R",cantidadPasos) #Devuelve los pasos que toma ir a la derecha
    if turtle.ycor() > inicio[0]: #Si la coordenada esta arriba:
        paso2 = pasosDir("U",cantidadPasos) #Devuelve los pasos que toma ir arriba
    if turtle.ycor() < inicio[0]: #Si la coordenada esta abajo:
        paso2 = pasosDir("D",cantidadPasos) #Devuelve los pasos que toma ir abajo
    
    turtle.speed(1) #Indica la velocidad de la animcacion
    
    turtle.listen() #Espera que una de las siguientes teclas sea presionada
    turtle.onkey(up,"Up") #Dirije al artón haci arriba
    turtle.onkey(down,"Down") #Dirije al artón hacia abajo
    turtle.onkey(left,"Left") #Dirije al artón hacia la izquierda
    turtle.onkey(right,"Right") #Dirije al artón hacia la derecha
    
    actual = inicio #Define una variable auxiliar
    score = score + paso1 + paso2 #Establece el score "inicial"
    
    while(score>=0): #Mientras el score sea mayor o igual a 0, no se cerrará el ciclo
        turtle.clearstamp(b) #Borra la posición inicial del ratón
        
        if nivel[int(actual[1]/24-inicio[1])][int(actual[0]/24-inicio[0])] == queso: #Si el ratón toca el queso:
            turtle.bye() #Cierra la ventana de gráficos
            return #Termina la función
        
        paso1 = 0
        paso2 = 0
        if turtle.xcor() > actual[1] or turtle.ycor() > actual[0] or turtle.xcor() < actual[1] or turtle.ycor() < actual[0]: #Si el ratón se movió:
            if turtle.xcor() > actual[1]: #Si se mueve a la izquierda:
                paso1 = pasosDir("L",cantidadPasos) #Contabiliza los pasos hacia la izquierda
            if turtle.xcor() < actual[1]: #Si se mueve a la derecha:
                paso1 = pasosDir("R",cantidadPasos) #Contabiliza los pasos hacia la derecha
            if turtle.ycor() > actual[0]: #Si se mueve arriba:
                paso2 = pasosDir("U",cantidadPasos) #Contabiliza los pasos hacia arriba
            if turtle.ycor() < actual[0]: #Si se mueve abajo:
                paso2 = pasosDir("D",cantidadPasos) #Contabiliza los pasos hacia abajo
                
            score = score - paso1 - paso2 #Actualiza los pasos restantes
            
            pen.clear() #Borra el anterior escrito con el lápiz
            pen.write("Vidas restantes: {}".format(score), align = "center", font = ("Arial", 15, "normal")) #Escribe la vida restante
            
            actual = (turtle.ycor(),turtle.xcor()) #Define la coordenada actual, después del movimiento
            
    turtle.bye() #Cierra la ventana de gráficos

def construir_laberinto(nivel,ratoncito,queso,pared,libre): #grafica y colorea el laberinto
    wn = turtle.Screen() #Abre la ventana donde podremos graficar
    wn.bgcolor("black") #Establece el color del fondo de la ventana
    wn.title("Laberinto del ratón") #Titula a la ventana
    wn.setup(500,500) #Establece el tamaño de la ventana
    
    pen = Pen() #Establece el lapiz con el que se colorean las casillas vacias del mapa
    pen1 = Pen1() #Establece un lapiz con el que se colorean las casillas que representan las paredes
    pen2 = Pen2() #Establece el lapiz con el que se coloreara el punto de llegada
    pen3 = Pen3() #Establece el lapiz con el que se coloreara el punto de partida
    for fila in range(len(nivel)): #Según cada fila:
        for columna in range(len(nivel[fila])): #Según cada columna:
            casilla = nivel[len(nivel)-fila-1][columna] #Permite colorear cada casilla por separado
            screen_x = columna*24 #Le da un largo a cada casilla
            screen_y = fila*24 #Le da un alto a cada casilla
            if casilla == libre: #Verifica si la casilla está vacía
                pen.goto(screen_x,screen_y) #Se dirije a la casilla verificada como vacia
                pen.stamp() #Pinta la casilla del color asignado a las casillas vacías
            if casilla == pared: #Verifica si la casilla es una pared
                pen1.goto(screen_x,screen_y) #Se dirije a la casilla verificada como pared
                pen1.stamp() #Pinta la casilla del color asignado a las casillas que son paredes
            if casilla == queso: #Verifica si la casilla es la meta
                pen2.goto(screen_x,screen_y) #Se dirije a la casilla verificada como la meta
                pen2.stamp() #Pinta la casilla del color asignado a las casilla que es la mera
            if casilla == ratoncito: #Verifica si la casilla es el inicio
                pen3.goto(screen_x,screen_y) #Se dirije a la casilla verificada como el inicio
                pen3.stamp() #Pinta la casilla del color asignado a las casillas que es el inicio

def inicio_raton(nivel,pasos,ratoncito): #declara los movimientos del ratón
    raton = Turtle() #crea al raton
    for fila in range(len(nivel)): #Según cada fila:
        for columna in range(len(nivel[fila])): #Según cada columna
            if nivel[fila][columna] == ratoncito: #Busca la posición que representa el inicio
                raton.goto(columna*24,(len(nivel[fila])-1-fila)*24) #Dirije al lápiz a esa posición de inicio
                a = raton.stamp() #Dibuja al raton en la casilla de su posición inicial
    
    raton.speed(1) #Determina la velocidad de la animación, es decir, de los movimientos del ratón
    for direccion in pasos: #Según cada elemento del conjunto de pasos:        
        if direccion == 'U': #Verifica si la dirección del ratón es hacia arriba
            raton.setheading(90) #Mueve al ratón para que su cabeza apunte a la casilla de arriba
        if direccion == 'D': #Verifica si la dirección del ratón es hacia abajo
            raton.setheading(270) #Mueve al ratón para que su cabeza apunte a la casilla de abajo
        if direccion == 'L': #Verifica si la dirección del ratón es hacia la izquierda
            raton.setheading(180) #Mueve al ratón para que su cabeza apunte a la casilla de la izquierda
        if direccion == 'R': #Verifica si la dirección del ratón es hacia la derecha
            raton.setheading(0) #Mueve al ratón para que su cabeza apunte a la casilla de la derecha
    
        raton.forward(24) #Mueve al ratón una casilla en la dirección que apunta
        raton.clearstamp(a) #Remueve la estampa de la linea 76, que servia para posiciona al ratón en el inicio
    
    turtle.bye() #Cierra la ventana que mostraba el laberinto

def topaPared(posicion,bloqueos,pared):
    for pared in bloqueos: #Entramos a una condicional 
        if posicion == pared: #Si la posición es igual a la pared, significa que la posición de la tortuga ha topado con la pared
            return True #Retornará verdadero de haberse topado con alguna pared
    return False #Retornará falso de no haberse topado con niguna pared

#entramos a un algoritmo recursivo
def buscaSalida(inicio,alternativas,estado,nivel,paredes,queso,pared): #busca la meta que debe buscar el ratón
    for opcion in alternativas: #Según cada alternativa:
        nuevoEstado = estado[:] #Crea una variable que servira de chivo expiatorio
        nuevoEstado.append(opcion) #Añade una de las alternativas a nuevoEstado
        
        y = inicio[0] #Asigna a y el valor con respecto al eje de ordenadas
        x = inicio[1] #Asigna a y el valor con respecto al eje de abscisas
        
        #se analizan los diferentes if
        if opcion == 'U': #Si la alternativa fue hacia arriba:
            y=y+1 #Aumenta el valor de y en una unidad
        if opcion == 'D': #Si la alternativa fue hacia abajo:
            y=y-1 #Decrece el valor de y en una unidad
        if opcion == 'L': #Si la alternativa fue hacia la izquierda:
            x=x-1 #Decrece el valor de x en una unidad
        if opcion == 'R': #Si la alternativa fue hacia la derecha:
            x=x+1 #Aumenta el valor de x en una unidad
        
        if (y<0 or y>=len(nivel) or x<0 or x>=len(nivel[0]) or topaPared((y,x),paredes,pared)): #Si las coordenadas del movimiento reciente estan fuera del rango del laberinto:
            continue #Termina la condicional sin pasar por las lineas restantes
        
        if nivel[y][x] == queso: #Si en las coordenadas aparece la letra S (que indicaría la salida):
            return nuevoEstado #Retorna el estado actual, es decir, los pasos tomados hasta ahora
        
        paredes.append((inicio))
        resultado = buscaSalida((y,x),alternativas,nuevoEstado,nivel,paredes,queso,pared) #Si excede el objetivo explorará otra alternativa
        if resultado != False: #Si no ha llegado hasta la meta y tampoco se ha pasado de largo:
            return resultado #Retorna el resultado, es decir, los pasos que debe seguir para llegar a la meta
    
    return False #si analizo todas las posibilidades y ninguna fue la solución, devuelve un valor falso

#inciso a
def incisoA(prenivel,ratoncito,queso,pared,libre): #inicia el inciso a)
    #para poner el laberinto al reves, y así pueda interpretarlo como un eje de coordenadas:
    nivel = [] #Definira la matriz a la cual se le asignaran los valores reacomodados
    for i in range(len(prenivel)): #Según cada fila:
        nivel.append(prenivel[len(prenivel)-1-i]) #Asigna la fila para que quede al revés, respecto a las filas

    #busca el inicio y la meta de raton
    paredes = [] #Definira las paredes, las cuales el ratón no puede atravesar y delimitan sus movimientos
    for fila in range(len(nivel)): #Según cada fila:
        for columna in range(len(nivel[0])): #Según cada columna:
            if nivel[fila][columna] == ratoncito: #Si la coordenada tiene la letra "I":
                inicio = (fila,columna) #Asigna la coordenada del final o la meta
            if nivel[fila][columna] == pared: #Si la coordenada tiene la letra "Z":
                paredes.append((fila,columna)) #Anexa las coordenadas de cada pared, y así con cada pared del laberinto

    alternativas = ('U','D','L','R') #Son las diferentes alternativas

    estado = [] #Guardara las direcciones que debera seguir el ratón para llegar a la meta

    solucion = buscaSalida(inicio,alternativas,estado,nivel,paredes,queso,pared) #Para buscar la mejor solucion

    construir_laberinto(prenivel,ratoncito,queso,pared,libre) #Para la visualización del tablero
    inicio_raton(prenivel,solucion,ratoncito) #Funcion donde definimos a la "tortuga" o "ratón" dentro del laberinto
    
#inciso b
def incisoB(prenivel,ratoncito,queso,pared,libre): #inicia el inciso b)
    largoNivel = len(prenivel[0]) #Establece el largo del laberinto
    altoNivel = len(prenivel) #Establece el alto del laberinto

    for fila in range(len(prenivel)): #Según cada fila: 
        for columna in range(len(prenivel[0])): #Según cada columna:
            if prenivel[fila][columna] == ratoncito: #Si la coordenada tiene la letra "I":
                inicio = [columna,fila] #Asigna la coordenada del final o la meta

    rutaCorta = [] #Establece que las coordenadas de la ruta estarán en un arreglo
    rutaCorta = mejorRuta(prenivel,inicio,largoNivel,altoNivel,queso,pared) #Halla las coordenadas para la ruta mas corta según la cantidad de pasos

    movimientos = [] #Establece que las direcciones de la ruta sera un arreglo
    movimientos = mov(rutaCorta) #Halla las direcciones para la ruta más corta según la cantidad de pasos
    
    construir_laberinto(prenivel,ratoncito,queso,pared,libre) #Para la visualización del tablero
    inicio_raton(prenivel,movimientos,ratoncito) #Funcion donde definimos a la "tortuga" o "ratón" dentro del laberinto
    
#inciso c
def incisoC(prenivel,ratoncito,queso,pared,cantidadPasos,libre): #inicia el inciso c)
    inicio = ()
    for i in range(len(prenivel)): #Según cada fila:
        for j in range(len(prenivel[0])): #Según cada columna:
            if prenivel[i][j] == ratoncito:
                inicio = (j,len(prenivel)-i-1) #Determina la posición inicial del ratón
    
    print("Ingresa las vidas que tendrá el ratón") #Pide introducir las vidas que tendrá el ratón
    vidas = int(input())
    
    construir_laberinto(prenivel,ratoncito,queso,pared,libre) #Construye el laberinto
    pasosMovimiento(prenivel,inicio,vidas,cantidadPasos,ratoncito,queso) #Permite que el rayón se mueva libremente

def menu(): #Menu que permitira seleccionar entre uno de los incisos o salir de la ejecución del programa:
    opc= int(input("BIENVENIDO AL MENÚ\n" +
             "¿QUÉ DESEAS REALIZAR?\n" +
             "1)Encontrar una salida al laberinto\n" +
             "2)Encontrar la mejor salida\n" +
             "3)Vida  consumida\n" +
             "4)Salir\n")) #Indica las posibles opciones a elegir para el usuario
    return opc #Retorna un valor que luego servirá para ejecutar la opción deseada

def main(): #Es la función principal    
    opcion = 0 #Ledaun valor a la variable, para que no tenga problemas al entrar al condicional
    print("***L A B E R I N T O**") #Imprime "Laberinto"
    
    print("Ingrese el nombre del archivo de tipo json que representará el laberinto:") #Pide el nombre del archivo json
    nombre_json = input()
    prenivel = json_py(nombre_json)  #Define el tablero del laberinto
    
    print("Indique el simbolo que representa al raton:") #Pide la letra que representa la posición inicial del ratón
    ratoncito = input()
    
    print("Indique el simbolo que representa al queso:") #Pide la letra que representa el queso que busca el ratón
    queso = input()
    
    print("Indique el simbolo que representa a las paredes:") #Pide la letra que representa las paredes del laberinto
    pared = input()
    
    print("Indique el simbolo que representa al camino libre:") #Pide la letra que representa las paredes del laberinto
    libre = input()
    
    if opcion != 4: #Si la opcion no sea la de salir de la ejecución:
        opcion = menu() #Asigna un valor a la varibale
        if opcion == 1: #Si el valor de la variable es 1:
            incisoA(prenivel,ratoncito,queso,pared,libre) #Ejecuta la consigna del inciso a)
        if opcion == 2: #Si el valor de la variable es 2:
            incisoB(prenivel,ratoncito,queso,pared,libre) #Ejecuta la consigna del inciso b)
        if opcion == 3: #Si el valor de la variable es 3:
            print("Indique la cantidad de pasos que toma moverse hacia arriba, abajo, a la izquierda y a la derecha:") #Pide la cantidad de pasos de cada movimiento
            arriba = int(input("Arriba: "))
            abajo = int(input("Abajo: "))
            izquierda = int(input("Izquierda: "))
            derecha = int(input("Derecha: "))
    
            cantPasos = [['U',arriba],['D',abajo],['L',derecha],['R',izquierda]]
            
            incisoC(prenivel,ratoncito,queso,pared,cantPasos,libre) #Ejecuta la consigna del inciso c)
    
    print("HASTA LUEGO, VUELVE PRONTO") #Imprime una despedida

main() #Ejecuta el programa