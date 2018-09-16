#include <new>
using std::nothrow;

template <typename T>
struct Deque
{
	T *E,*D,*I,*F;
};

template <typename T>
bool inicializar (Deque<T> &D)
{
	D.I = new(nothrow) T[1];
	if (D.I == nullptr) {return true;}
	D.F = D.I;
	D.E = nullptr;
	D.D = nullptr;
	return false;
}

template <typename T>
void terminar (Deque<T> &D)
{
	delete[] D.I;
}

template <typename T>
bool vazio (Deque<T> &D)
{
	return D.E == nullptr;
}

template <typename T>
bool cheio (Deque<T> &D)
{
	return ((D.D == (D.E - 1)) || ((D.I == D.E) && (D.F == D.D)));
}

template <typename T>
bool inserir_esq(Deque<T> &D, T e)
{
if(vazio(D))
{
D.D = D.E = D.I;
*D.E = e;
return false;
}
else if(cheio(D))
{
int novo_t = ((D.F - D.I)+1)*2;
T *V = new(nothrow) T[novo_t];
if(V == nullptr) {return true;}
T *p = D.E;
T *q = V;
if ((D.E == D.D)&&(D.E == D.I)&&(D.E == D.F))
{
	*q = *p;
	++q;
}
else
{
	do
	{
		*q = *p;
		if (p == D.F)
		{
			p = D.I;
			++q;
		}
		else
		{
			++q;
			++p;
		}
		}while(p != D.E);
	}
	delete[] D.I;
	D.I = V;
	D.F = D.I + (novo_t - 1);
	D.E = D.I;
	D.D = q - 1;
}
(D.E == D.I)?(D.E = D.F):--D.E;
*D.E = e;
return false;
}

template <typename T>
bool inserir_dir(Deque<T> &D, T e)
{
if(vazio(D))
{
D.D = D.E = D.I;
*D.D = e;
return false;
}
else if(cheio(D))
{
int novo_t = ((D.F - D.I)+1)*2;
T *V = new(nothrow) T[novo_t];
if(V == nullptr) {return true;}
T *p = D.E;
T *q = V;
if ((D.E == D.D)&&(D.E == D.I)&&(D.E == D.F))
{
	*q = *p;
	++q;
}
else
{
	do
	{
		*q = *p;
		if (p == D.F)
		{
			p = D.I;
			++q;
		}
		else
		{
			++q;
			++p;
		}
		}while(p != D.E);
	}
	delete[] D.I;
	D.I = V;
	D.F = D.I + (novo_t - 1);
	D.E = D.I;
	D.D = q - 1;
}
(D.D == D.F)?(D.D = D.I):++D.D;
*D.D = e;
return false;
}

template <typename T>
T remover_esq(Deque <T> &D)
{
	T p = *D.E;
	if (D.E == D.D)
	{
		D.E = nullptr;
	}
	else if (D.E == D.F)
	{
		D.E = D.I;
	}
	else
	{
		++D.E;
	}
	return p;
}

template <typename T>
T remover_dir(Deque <T> &D)
{
	T p = *D.D;
	if (D.E == D.D)
	{
		D.E = nullptr;
	}
	else if (D.D == D.I)
	{
		D.D = D.F;
	}
	else
	{
		--D.D;
	}
	return p;
}