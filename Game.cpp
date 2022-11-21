#include "Game.h"
#include <string>
#include <iostream>
using namespace std;

Game::Game()
{
	round = 0;
	cellsAlive = 0;
	cellsBornThisRound = 0;
	cellsDiedThisRound = 0;
	totalCellsBorn = 0;
	totalCellsDied = 0;
	meanBirths = 0;
	meanDeaths = 0;
	gameChangedLastRound = false;
	gameChangedThisRound = false;
	isGameFrozen = false;
	board = NULL;
}

Game::~Game()
{
	delete board;
}

Board<Cell*>* Game::getBoard()
{
	return this->board;
}

void Game::setBoard(int width, int large, int height)
{
	this->board = new Board<Cell*>(width, large, height);
}

void Game::askBoardSize()
{
	int width, large, height;
	cout << "Ingrese la cantidad de filas del tablero (coordenada x): " << endl;
	cin >> width;
	cout << endl;
	cout << "Ingrese la cantidad de columnas del tablero (coordenada y): ";
	cin >> large;
	cout << endl;
	cout << "Ingrese la cantidad de planos del tablero (coordenada z): ";
	cin >> height;
	cout << endl;

	this->setBoard(width, large, height);
}

void Game::askInitialCellsAlive() {
	int numberOfCells;
	cout << "Ingrese la cantidad inicial de células vivas en el tablero: ";
	cin >> numberOfCells;
	while (!this->board->isValidSize(numberOfCells)) {
		cout << "La cantidad de células ingresadas no coincide con el tamaño del tablero: " << endl;
		cout << "Ingrese una cantidad inicial de células vivas válida: ";
		cin >> numberOfCells;
	}
	cout << endl;
	this->cellsAlive = numberOfCells;
}

void Game::askCellStateLimits()
{
	int width, large, height;
	cout << "Ingrese ancho:" << endl;
	cin >> width;
	cout << endl;
	cout << "Ingrese largo:" << endl;
	cin >> large;
	cout << endl;
	cout << "Ingrese alto:" << endl;
	cin >> height;
	cout << endl;
}

void Game::askPositionForSingleCellAlive() {
	int x, y, z;

	cout << "Coordenada x: ";
	cin >> x;
	while (!this->board->isValidEdge(x, this->board->getWidth()))
	{
		cout << "La coordenada indicada excede las dimensiones del tablero. El número de la fila debe ser menor o igual a " << this->board->getWidth() << "." << endl;
		cout << "Coordenada x: ";
		cin >> x;
	}
	cout << "Coordenada y: ";
	cin >> y;
	while (!this->board->isValidEdge(y, this->board->getLength()))
	{
		cout << "La coordenada indicada excede las dimensiones del tablero. El número de la fila debe ser menor o igual a " << this->board->getLength() << "." << endl;
		cout << "Coordenada y: ";
		cin >> y;
	}
	cout << "Coordenada z: ";
	cin >> z;
	while (!this->board->isValidEdge(z, this->board->getHeight()))
	{
		cout << "La coordenada indicada excede las dimensiones del tablero. El número de la fila debe ser menor o igual a " << this->board->getHeight() << "." << endl;
		cout << "Coordenada z: ";
		cin >> z;
	}

	this->board->fillBox(x, y, z, new NormalCell(new CellGenes(50, 100, 150), ALIVE));
}

void Game::askPositionForAllCellsAlive()
{
	int x,y,z; 
	for (int i = 1; i <= this->cellsAlive; i++)
	{
		cout << "Ingrese la posición de la celúla n° " << i << endl;
		this->askPositionForSingleCellAlive();
	}

}

void Game::setConfigOne()
{
	setBoard(5, 5, 5);
	List<Cell*>* cells = new List<Cell*>();
	for (int i = 1; i <= 30; i++)
	{
		cells->add(new NormalCell(new CellGenes(0, 250, 0), ALIVE));
	}
	for (int i = 1; i <= 20; i++)
	{
		cells->add(new RadioactiveCell(new CellGenes(250, 0, 0), ALIVE));
	}
	for (int i = 1; i <= 10; i++)
	{
		cells->add(new NormalCell(new CellGenes(), DEAD));
	}
	for (int i = 1; i <= 25; i++)
	{
		cells->add(new ZombieCell(new CellGenes(0, 0, 250), ALIVE));
	}
	for (int i = 1; i <= 20; i++)
	{
		cells->add(new RadioactiveCell(new CellGenes(), DEAD));
	}
	for (int i = 1; i <= 10; i++)
	{
		cells->add(new NormalCell(new CellGenes(239, 247, 10), ALIVE));
	}
	for (int i = 1; i <= 5; i++)
	{
		PortalChildCell* portalChild = new PortalChildCell(new CellGenes(), ALIVE);
		PortalFatherCell* portalFather = new PortalFatherCell(portalChild, new CellGenes(), ALIVE);
		cells->add(portalChild);
		cells->add(portalFather);
	}

	this->board->fillWith(cells);
}

void Game::setConfigTwo()
{
	setBoard(3, 3, 3);
	List<Cell*>* cells = new List<Cell*>();
	for (int i = 1; i <= 9; i++)
	{
		cells->add(new NormalCell(new CellGenes(250, 250, 0), ALIVE));
	}
	for (int i = 1; i <= 9; i++)
	{
		cells->add(new RadioactiveCell(new CellGenes(250, 0, 0), ALIVE));
	}
	for (int i = 1; i <= 9; i++)
	{
		cells->add(new NormalCell(new CellGenes(), DEAD));
	}

	this->board->fillWith(cells);
}

void Game::nextRound()
{
	this->board->defineNewStates();
	this->printBoard();
	this->printStatistics();
	this->showOptionsMenu();
}

void Game::initializeGame()
{
	this->round = 0;
	this->cellsAlive = 0;
	this->cellsBornThisRound = 0;
	this->cellsDiedThisRound = 0;
	this->totalCellsBorn = 0;
	this->totalCellsDied = 0;
	this->meanBirths = 0;
	this->meanDeaths = 0;
	this->gameChangedLastRound = false;
	this->gameChangedThisRound = false;
	this->isGameFrozen = false;

	if (this->board)
	{
		delete board;
	}

	this->showInitializationMenu();
}
 


// Muestra el menú para la inicialización del tablero
void Game::showInitializationMenu()
{
	unsigned int input;

	cout << "====================" << endl;
	cout << "= Juego de la vida =" << endl;
	cout << "====================" << endl;
	cout << endl;

	cout << "Seleccione el tipo de inicialización:" << endl;
	cout << "1. Manual" << endl;
	cout << "2. Configuración 1" << endl;
	cout << "3. Configuración 2" << endl;
	cout << "4. Configuración 3" << endl;
	cout << endl;
	cout << "Ingrese una opción: ";
	cin >> input;
	cout << endl;
	while (input < 1 || input > 4)
	{
		cout << "La opción ingresada no es válida." << endl;
		cout << "Ingrese una opción: ";
		cin >> input;
		cout << endl;
	}

	switch (input - 1)
	{
	case MANUAL:
		/* showManualInitializationMenu(game);
		game->nextRound(); */
		this->showManualInitializationMenu();
		break;
	case CONFIG_ONE:
		this->setConfigOne();
		break;
	case CONFIG_TWO:
		this->setConfigTwo();
		break;
	case CONFIG_THREE:

		break;
	default:
		break;
	}

	this->printBoard();
	cout << "El estado del tablero se muestra en las imágenes .bmp generadas." << endl;
	cout << "Presione una tecla para continuar al próximo turno...";
	cin.ignore();
	cin.get();
	this->nextRound();
}

// Muestra el menú para la inicialización manual del tablero
void Game::showManualInitializationMenu() {
	this->askBoardSize();
	this->board->fillCompletelyWith(new NormalCell(new CellGenes(0, 0, 0), DEAD));
	this->askInitialCellsAlive();
	this->askPositionForAllCellsAlive();

}

// Muestra el menú con las opciones del juego
void Game::showOptionsMenu()
{
	unsigned int input;

	cout << "1. Ejecutar un turno" << endl;
	cout << "2. Reiniciar juego" << endl;
	cout << "3. Terminar juego" << endl;
	cout << endl;
	cout << "Ingrese una opción: ";
	cin >> input;
	cout << endl;
	while (input < 1 || input > 3)
	{
		cout << "La opción ingresada no es válida." << endl;
		cout << "Ingrese una opción: ";
		cin >> input;
	}

	switch (input - 1)
	{
	case NEXT_ROUND:
		this->nextRound();
		break;
	case RESTART:
		this->initializeGame();
		break;
	case END_GAME:
		cout << "¡Juego terminado!" << endl;
		exit(0);
		break;
	default:
		break;
	}
};

void Game::printBoard()
{
	BMP AnImage;
	// Set size to 640 × 480
	AnImage.SetSize(1024, 768);
	// Set its color depth to 8-bits
	AnImage.SetBitDepth(16);

	for (int i = 1; i <= this->getBoard()->getWidth(); i++)
	{
		for (int k = 1; k <= this->getBoard()->getLength(); k++)
		{
			for (int j = 1; j <= this->getBoard()->getHeight(); j++)
			{
				int* genes = this->getBoard()->getBox(i, j, k)->getData()->getGenes()->getGenesValues();
				RGBApixel NewColor;
				NewColor.Red = genes[0];
				NewColor.Green = genes[1];
				NewColor.Blue = genes[2];

				RGBApixel White;
				White.Red = 255;
				White.Green = 255;
				White.Blue = 255;

				for (int l = 0; l < 100; l++)
				{
					for (int m = 0; m < 100; m++)
					{
						if (m == 0 || l == 0 || m == 99 || l == 99)
						{
							AnImage.SetPixel(j * 100, k * 100, White);
						}
						else
						{
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
}

// Imprime las estadísticas
void Game::printStatistics()
{
	cout << "Cantidad de células vivas: " << this->cellsAlive << endl;
	cout << "Cantidad de células que nacieron en este turno: " << this->cellsBornThisRound << endl;
	cout << "Cantidad de células que murieron en este turno: " << this->cellsDiedThisRound << endl;

	this->meanBirths = static_cast<float>(this->totalCellsBorn) / static_cast<float>(this->round);
	cout << "Promedio de nacimientos: " << this->meanBirths << endl;

	this->meanDeaths = static_cast<float>(this->totalCellsDied) / static_cast<float>(this->round);
	cout << "Promedio de muertes: " << this->meanDeaths << endl;

	if (this->gameChangedLastRound == false && this->gameChangedThisRound == false)
	{
		this->isGameFrozen = true;
	}
	cout << "El juego se congeló: " << (this->isGameFrozen == true ? "Sí" : "No") << endl;

	cout << endl;
};