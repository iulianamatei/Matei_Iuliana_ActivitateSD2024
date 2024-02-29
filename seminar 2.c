#include<stdio.h>
#include<malloc.h>

struct Calculator
{
	char* serie;
	float pret;
	int nrPorturi;
};


struct Calculator initializare(const char* serie, float pret, int nrPorturi)
{
	struct Calculator c;
	c.serie = (char*)malloc(sizeof(char) * (strlen(serie) + 1));
	strcpy(c.serie, serie);
	c.nrPorturi = nrPorturi;
	c.pret = pret;
	return c;
}

void afisarecalculator(struct Calculator c)
{
	printf("calculatorul cu seria %s, costa %5.2f si are %d porturi\n", c.serie, c.pret, c.nrPorturi);
}

void afisareVectorCalculatoare(struct Calculator* vector, int nrCalculatoare)
{
	if (nrCalculatoare > 0 && vector != 0)
		for (int i = 0; i < nrCalculatoare; i++)
			afisarecalculator(vector[i]);
}

//functie care copiaza primele n elemente dintr-un vector de n elemente
//returnam pointer

struct Calculator* copiazaCalculatoare(struct Calculator* calculatoare, int nrCalculatoare, int nrCalculatoareCopiate)
{
	struct Calculator* copiate = (struct Calculator*)malloc(sizeof(struct Calculator) * nrCalculatoareCopiate);
	for (int i = 0; i < nrCalculatoareCopiate; i++)
	{
		copiate[i] = calculatoare[i];
		copiate[i].serie = (char*)malloc(sizeof(char) * (1 + strlen(calculatoare[i].serie)));
		strcpy(copiate[i].serie, calculatoare[i].serie);
	}
	return copiate;
}
struct Calculator* copiazaCalculatoareCuMUltePorturi(struct Calculator* calculatoare, int nrCalculatoare, int pragNrporturi, int* nrCalculatoarePorturi)
{
	*nrCalculatoarePorturi = 0;
	for (int i = 0; i < nrCalculatoare; i++)
	{
		if (calculatoare[i].nrPorturi > pragNrporturi)
		{
			(*nrCalculatoarePorturi)++;
		}
	}
	struct Calculator* v = (struct Calculator*)malloc(sizeof(struct Calculator) * (*nrCalculatoarePorturi));
	int k = 0;
	for (int i = 0; i < nrCalculatoare; i++)
	{
		if (calculatoare[i].nrPorturi > pragNrporturi)
		{
			v[k++] = initializare(calculatoare[i].serie, calculatoare[i].pret, calculatoare[i].nrPorturi);

		}
	}
	return v;
}

void dezalocare(struct calculator** vector, int* dim)
{
	for (int i = 0; i < (*dim); i++)
	{
		free((*vector)[i].serie);

	}
	free(*vector);
	*vector = NULL;
	*dim = 0;
}

void main()
{
	//int v[10];//alocat static pe stack
	//int* v1;//ca sa alocam dinamic initializam un pointer la adresa primului element

	int nrCalculatoare = 5;

	struct Calculator* calculatoare = (struct Calculator*)malloc(sizeof(struct Calculator) * nrCalculatoare);
	for (int i = 0; i < nrCalculatoare; i++)
	{
		calculatoare[i] = initializare("1234567890", i * 20 + 10, i + 1);
	}

	afisareVectorCalculatoare(calculatoare, nrCalculatoare);
	int nrCalculatoareCopiate = 3;

	struct Calculator* calculatoareCopiate = copiazaCalculatoare(calculatoare, nrCalculatoare, nrCalculatoareCopiate);



	afisareVectorCalculatoare(calculatoareCopiate, nrCalculatoareCopiate);

	int nrCalculatoarePorturi = 0;
	struct Calculator* calculatoarePorturi = copiazaCalculatoareCuMUltePorturi(calculatoare, nrCalculatoare, 3, &nrCalculatoarePorturi);

	printf("\n\n\n");


	afisareVectorCalculatoare(calculatoarePorturi, nrCalculatoarePorturi);


}

//hvuuyuv