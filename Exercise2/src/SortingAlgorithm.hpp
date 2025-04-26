#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

// Definisce un concept "Sortable": il tipo T è considerato ordinabile
// se supporta l'operatore < tra due istanze e restituisce un valore convertibile in bool
template<typename T>
concept Sortable = requires(T& t){
	{t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	for(unsigned int i = 0; i < n-1; i++)
	{
		for (unsigned int j = i+1; j < n; j++)
		{
			if (v[j] < v[i])
			{
				swap(v[i],v[j]);
			}
		}
	}
}

template <typename T>
void heapify(std::vector<T>& v, int n, int i)
// Funzione che ripristina la proprietà di heap nel sottoalbero con radice i
// v: vettore che rappresenta l'heap
// n: dimensione dell'heap (può essere minore della dimensione totale del vettore)
// i: indice del nodo da cui partire
{
    int largest = i; // Inizializza la radice come il nodo più grande
    int left = 2 * i + 1; // Indice del figlio sinistro
    int right = 2 * i + 2; // Indice del figlio destro

    // Se il figlio sinistro è più grande della radice
    if (left < n && v[left] > v[largest])
        largest = left;

    // Se il figlio destro è più grande della radice (o del figlio sinistro)
    if (right < n && v[right] > v[largest])
        largest = right;

    // Se la radice non è il nodo più grande, scambia 
    if (largest != i)
    {
        std::swap(v[i], v[largest]);

        // Ripristina la proprietà dell'heap
        heapify(v, n, largest);
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{ 
	const unsigned int n = v.size();
    // Costruisce l'heap 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    // Estrae gli elementi uno alla volta
    for (int i = n - 1; i >= 1; i--)
    {
        // Sposta la radice (l'elemento massimo) alla fine del vettore
        std::swap(v[0], v[i]);

        // Ripristina la proprietà dell'heap
        heapify(v, i, 0);
    }
}

}


