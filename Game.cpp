#include "Game.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game()
{
	round = 0;
	cellsBornLastRound = 0;
	cellsDiedLastRound = 0;
	totalCellsBorn = 0;
	totalCellsDied = 0;
	meanBirths = 0;
	meanDeaths = 0;
	roundsFrozen = 0;

	neighboursToBorn = 0;
	minNeighboursToDie = 0;
	maxNeighboursToDie = 0;

	gameChangedLastRound = false;
	gameChangedThisRound = false;
	isGameFrozen = false;
	ongoingGame = true;
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

int Game::askInitialCellsAlive() {
	int numberOfCells;
	cout << "Ingrese la cantidad inicial de células vivas en el tablero: ";
	cin >> numberOfCells;
	while (!this->board->isValidSize(numberOfCells)) {
		cout << "La cantidad de células ingresadas no coincide con el tamaño del tablero: " << endl;
		cout << "Ingrese una cantidad inicial de células vivas válida: ";
		cin >> numberOfCells;
	}
	cout << endl;
	return numberOfCells;
	
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

	Cell* cell = new NormalCell(ALIVE);
	cell->setNeighboursToBorn(this->neighboursToBorn);
	cell->setMinNeighboursToDie(this->minNeighboursToDie);
	cell->setMaxNeighboursToDie(this->maxNeighboursToDie);
	this->board->fillBox(x, y, z, new NormalCell(ALIVE));
}

void Game::askPositionForAllCellsAlive(int cellsAlive)
{
	for (int i = 1; i <= cellsAlive; i++)
	{
		cout << "Ingrese la posición de la celúla n° " << i << endl;
		this->askPositionForSingleCellAlive();
	}

}

void Game::askNeighboursToBorn(){
	int neighboursToBorn;
	cout << "Ingrese la cantidad de células X1 vivas necesarias para nacer: ";
	cin >> neighboursToBorn;
	while (!this->board->isValidSize(neighboursToBorn)) {
		cout << "La cantidad de células ingresadas no es válido para el tamaño del tablero: " << endl;
		cout << "Ingrese una cantidad de células X1 vivas necesarias para nacer válida: ";
		cin >> neighboursToBorn;
	}
	cout << endl;
	this->neighboursToBorn = neighboursToBorn;
}


void Game::askMinNeighboursToDie() {
	int minNeighboursToDie;
	cout << "Ingrese la cantidad mínima de células X2 vivas necesarias para permanecer viva: ";
	cin >> minNeighboursToDie;
	while (!this->board->isValidSize(minNeighboursToDie)) {
		cout << "La cantidad de células ingresadas no es válido para el tamaño del tablero: " << endl;
		cout << "Ingrese una cantidad mínima de células X2 vivas necesarias para permanecer viva válida: ";
		cin >> minNeighboursToDie;
	}
	cout << endl;
	this->minNeighboursToDie = minNeighboursToDie;
}


void Game::askMaxNeighboursToDie() {
	int maxNeighboursToDie;
	cout << "Ingrese la cantidad máxima de células X3 vivas necesarias para permanecer viva: ";
	cin >> maxNeighboursToDie;
	while (!this->board->isValidSize(maxNeighboursToDie)) {
		cout << "La cantidad de células ingresadas no es válido para el tamaño del tablero: " << endl;
		cout << "Ingrese una cantidad máxima de células X3 vivas necesarias para permanecer viva válida: ";
		cin >> maxNeighboursToDie;
	}
	cout << endl;
	this->maxNeighboursToDie = maxNeighboursToDie;

}



int Game::countCellsAlive() {
	int cellsAlive = 0;
	for (int x = 1; x <= this->board->getWidth(); x++)
	{
		for (int y = 1; y <= this->board->getLength(); y++)
		{
			for (int z = 1; z <= this->board->getHeight(); z++)
			{
				if (this->board->getBox(x, y, z)->getData()->isAlive()) {
					cellsAlive++;
				}
			}
		}
	}
	return cellsAlive;
}



void Game::nextRound()
{
	this->cleanLastTransitions();
	this->board->defineNewStates();
	this->updateCellsStates();
	this->updateTotalTransitions();

	this->updateFrozenState();
	this->round++;
}
void Game::cleanLastTransitions() {
	this->cellsBornLastRound = 0;
	this->cellsDiedLastRound = 0;
}

void Game::updateTotalTransitions() {
	this->totalCellsBorn += this->cellsBornLastRound;
	this->totalCellsDied += this->cellsDiedLastRound;

}

void Game::updateCellsStates() {
	for (int x = 1; x <= this->board->getWidth(); x++)
	{
		for (int y = 1; y <= this->board->getLength(); y++)
		{
			for (int z = 1; z <= this->board->getHeight(); z++)
			{
				TransitionState transition = this->board->getBox(x, y, z)->getData()->switchStates();
				this->countTransitions(transition);
			}
		}
	}
}

void Game::countTransitions(TransitionState transition) {
	if (transition==NEW_BORN) {
		this->cellsBornLastRound++;
	}
	if (transition == NEW_DEATH) {
		this->cellsDiedLastRound++;
	}
}

void Game::initializeGame()
{
	this->round = 0;
	this->cellsBornLastRound = 0;
	this->cellsDiedLastRound = 0;
	this->totalCellsBorn = 0;
	this->totalCellsDied = 0;
	this->meanBirths = 0;
	this->meanDeaths = 0;
	this->roundsFrozen = 0;
	this->gameChangedLastRound = false;
	this->gameChangedThisRound = false;
	this->isGameFrozen = false;
	this->ongoingGame = true;

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
		this->showManualInitializationMenu();
		break;
	case CONFIG_ONE:
		this->setConfigOne();
		break;
	case CONFIG_TWO:
		this->setConfigTwo();
		break;
	case CONFIG_THREE:
		this->setConfigThree();
		break;
	default:
		break;
	}

	this->showGameStatus();
	this->showOptionsMenu();

}

// Muestra el menú para la inicialización manual del tablero
void Game::showManualInitializationMenu() {
	this->askBoardSize();
	this->board->fillCompletelyWith(new NormalCell(DEAD));
	int cellsAlive = this->askInitialCellsAlive();
	this->askNeighboursToBorn();
	this->askMinNeighboursToDie();
	this->askMaxNeighboursToDie();
	
	this->askPositionForAllCellsAlive(cellsAlive);
}

// Muestra el menú con las opciones del juego
void Game::showOptionsMenu()
{
	unsigned int input;

	cout << "1. Ejecutar un turno" << endl;
	cout << "2. Reiniciar juego" << endl;
	cout << "3. Terminar juego" << endl << endl;
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
		this->showGameStatus();
		this->showOptionsMenu();
		break;
	case RESTART:
		this->initializeGame();
		this->showInitializationMenu();
		break;
	case END_GAME:
		this->endGame();
		break;
	default:
		break;
	}
};

void Game::endGame()
{
	showEndingGameMessage();
	this->ongoingGame=false;
}

void Game::showEndingGameMessage() {
	cout << "Juego terminado!" << endl;
}

void Game::showGameStatus() {
	this->printBoard();
	this->printStatistics();

}


void Game::printBoard()
{
	BMP AnImage;
	// Set size to 640 × 480
	AnImage.SetSize(1024, 768);
	// Set its color depth to 8-bits
	AnImage.SetBitDepth(16);

	ostringstream convert;   // stream used for the conversion

	for (int i = 1; i <= this->getBoard()->getWidth(); i++)
	{
		for (int k = 1; k <= this->getBoard()->getLength(); k++)
		{
			for (int j = 1; j <= this->getBoard()->getHeight(); j++)
			{
				Cell* cell = this->getBoard()->getBox(i, j, k)->getData();
				int deadCellGenes[3] = {90,90,90};
				int* genes = cell->isAlive() ? cell->getGenes()->getGenesValues() : deadCellGenes;
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

				convert << i;

				string fileNameStr = "Imagen" + convert.str() + ".bmp";
				const char* fileName = fileNameStr.c_str();

				convert.str(""); // reset the string to be empty
				convert.clear(); // clear any error flags that may be set

				AnImage.WriteToFile(fileName);
			}
		}
	}
	cout << "El estado del tablero se muestra en las ";
	cout << this->getBoard()->getWidth();
	cout<< " imágenes .bmp generadas." << endl;
}

// Imprime las estadísticas
void Game::printStatistics()
{
	float meanDeaths = this->round == 0 ? (float)this->totalCellsDied : this->totalCellsDied / this->round;
	float meanBirths = this->round == 0 ? (float)this->totalCellsBorn : this->totalCellsBorn / this->round;
	cout << "Turno: " << this->round << endl;
	cout << "Cantidad de células vivas: " << this->countCellsAlive() << endl;
	cout << "Cantidad de células que nacieron en este turno: " << this->cellsBornLastRound << endl;
	cout << "Cantidad de células que murieron en este turno: " << this->cellsDiedLastRound << endl;
	cout << "Promedio de nacimientos: " << meanBirths << endl;
	cout << "Promedio de muertes: " << meanDeaths << endl;
	cout << "Juego congelado: " << (this->isGameFrozen == true ? "Sí" : "No") << endl;

	cout << endl;
};


void Game::updateFrozenState() {
	
	if (this->cellsBornLastRound == 0 && this->cellsDiedLastRound == 0) {
		this->roundsFrozen += 1;
		if (this->roundsFrozen >= 2) {
			this->isGameFrozen=true;
		}
	}
	else {
		this->roundsFrozen = 0;
		this->isGameFrozen=false;
	}

}

void Game::setConfigOne()
{
	setBoard(5, 5, 5);
	List<Cell*>* cells = new List<Cell*>();
	for (int i = 1; i <= 30; i++)
	{
		cells->add(new NormalCell(ALIVE));
	}
	for (int i = 1; i <= 20; i++)
	{
		cells->add(new RadioactiveCell(ALIVE));
	}
	for (int i = 1; i <= 10; i++)
	{
		cells->add(new NormalCell(DEAD));
	}
	for (int i = 1; i <= 25; i++)
	{
		cells->add(new ZombieCell(ALIVE));
	}
	for (int i = 1; i <= 20; i++)
	{
		cells->add(new RadioactiveCell(DEAD));
	}
	for (int i = 1; i <= 10; i++)
	{
		cells->add(new NormalCell(ALIVE));
	}
	for (int i = 1; i <= 5; i++)
	{
		PortalChildCell* portalChild = new PortalChildCell(ALIVE);
		PortalFatherCell* portalFather = new PortalFatherCell(portalChild, ALIVE);
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
		cells->add(new NormalCell(ALIVE));
	}
	for (int i = 1; i <= 9; i++)
	{
		cells->add(new RadioactiveCell(ALIVE));
	}
	for (int i = 1; i <= 9; i++)
	{
		cells->add(new NormalCell(DEAD));
	}

	this->board->fillWith(cells);
}

void Game::setConfigThree()
{
	setBoard(3, 3, 3);
	this->board->fillCompletelyWith(new NormalCell(DEAD));
	PortalChildCell* portalChild = new PortalChildCell(ALIVE);
	PortalFatherCell* portalFather = new PortalFatherCell(portalChild, ALIVE);
	RadioactiveCell* radioactive = new RadioactiveCell(ALIVE);
	ScaloCell* scaloni = new ScaloCell(ALIVE);
	ZombieCell* zombie = new ZombieCell(ALIVE);
	AryanCell* aryan = new AryanCell(ALIVE);
	this->board->fillBox(1,1,1, portalFather);
	this->board->fillBox(2,2,2, radioactive);
	this->board->fillBox(3,3,3, portalChild);
	this->board->fillBox(1,1,2, scaloni);
	this->board->fillBox(1,2,1, aryan);
	this->board->fillBox(1,1,3, zombie);


}