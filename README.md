# TP 2 Algoritmos
## Visualización y llenado de celulas
El metodo `setConfigTwo()` de la clase `Game` setea una configuración de un tablero de 3x3x3, un total de 27 celulas. 
De estas 27 celulas 9 son celulas normales con genes iniciales `(250,250,0)`
```
for (int i = 1; i <= 9; i++) {
		cells->add(new NormalCell(new CellGenes(250, 250, 0), ALIVE));
}
```
Las siguientes 9 celulas son radioactivas con genes `(250,0,0)`.
```
	for (int i = 1; i <= 9; i++) {
		cells->add(new RadioactiveCell(new CellGenes(250, 0, 0), ALIVE));
	}
```
Y las ultimas 9 celulas estan muertas. Estas celulas muertas son seteadas con el constructir `CellGenes()` que por defecto setea los genes en `(100,100,100)`.
```
	for (int i = 1; i <= 9; i++) {
		cells->add(new NormalCell(new CellGenes(), DEAD));
	}
```

Luego de que se configuran los tipos de celulas que se van a iniciar cuando arranque el juego, se llama al metodo `fillwith()` de la clase `Board`.
Este metodo llena el tablero con las celulas que se crearon antes, el orden de llenado esta definido en el metodo `append()`

```
template<class T>
void Board<T>::append(T element) {
	for (int x = 1; x <= getWidth(); x++)
	{
		for (int y = 1; y <= getLength(); y++)
		{
			for (int z = 1; z <= getHeight(); z++)
			{
				if (getBox(x, y, z)->isEmpty()) {
					fillBox(x, y, z, element);
					return;
				}
			}
		}
	}
	return;
}
```
Y se puede ver que el orden es `(x,y,z) = (1,1,1)->(1,1,2)->(1,1,3)->(1,2,1)->(1,2,2)....`
Es decir, que las primeras 9 celulas se van a ubicar en el plano `X = 1`.
Las segundas 9 celulas en el plano `X = 2` y las ultimas 9 en `X = 3`. 

Para verlas (o dibujarlas) en el mismo orden, se debe recorrer las coordenadas `Y,Z` para un mismo valor de `X`.
El segmento de código de a continuación recorre el tablero en ese sentido, es decir, para un determinado valor de `X` (en el for se nota `i`) recorremos el plano `Y,Z`
(`j,k` notadas en los dos siguientes `for`).
```
for (int i = 1; i <= game->getBoard()->getWidth(); i++) {
        for (int k = 1; k <= game->getBoard()->getLength(); k++) {
            for (int j = 1; j <= game->getBoard()->getHeight(); j++) {
                int* genes = game->getBoard()->getBox(i, j, k)->getData()->getGenes()->getGenesValues();
                //AnImage(i, j)->Red = genes[0];
                //AnImage(i, j)->Green = genes[1];
                //AnImage(i, j)->Blue = genes[2];
                RGBApixel NewColor;
                NewColor.Red = genes[0];
                NewColor.Green = genes[1];
                NewColor.Blue = genes[2];

                RGBApixel White;
                White.Red = 255;
                White.Green = 255;
                White.Blue = 255;

                for (int l = 0; l < 100; l++) {
                    for (int m = 0; m < 100; m++) {
                        if (m == 0 || l == 0 || m == 99 || l == 99) {
                            AnImage.SetPixel(j * 100, k * 100, White);
                        }
                        else {
                            AnImage.SetPixel(j * 100 + l, k * 100 + m, NewColor);
                        }

                    }
                }

                string fileNameStr = "Imagen" + to_string(i) + ".bmp";
                const char* fileName = fileNameStr.c_str();

                AnImage.WriteToFile(fileName);

            }
        }
    }
```
Luego, en la lines `AnImage.SetPixel(j * 100 + l, k * 100 + m, NewColor)` se pintan los pixeles que corresponden a la celula del plano indicado.