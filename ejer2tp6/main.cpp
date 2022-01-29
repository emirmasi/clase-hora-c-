#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;
class Hora
{
private:
    int horas,minutos,segundos;
public:
    Hora(int,int,int);//constr 1
    Hora(int);//constr2
    void mostrarHora();
    int convHoraEnSeg();
    Hora& operator++();//pre
    Hora& operator--();//pre
    Hora operator++(int);//pos
    Hora operator--(int);//pos
    Hora& operator+=(int segundos);
    Hora& operator-=(int segundos);

     friend ostream& operator <<(ostream& sal, const Hora& hora);
//    int sumarORestarSeg(int,int);
//    void sumarUnSeg();
//    void sumarHoras(Hora ,Hora);
   /* int decrementarSeg(int);
    int incrementarUnSeg(int);
    int decrementarUnSeg(int);*/
   friend Hora operator+(int segundos,const Hora& h2);
};
istream& operator >>(istream& ent, Hora& h);
//constructor 1
Hora::Hora(int _hora,int _minutos,int _segundos)
{
    horas = (_hora >=0 && _hora <=24)? _hora : 0;
    minutos = (_minutos >=0 && _minutos <= 60)? _minutos: 0;
    segundos = (_segundos >=0 && _minutos <=60)? _segundos : 0;
}
//constructor 2
Hora::Hora(int tiempoSeg)
{
    horas = tiempoSeg/3600;
    tiempoSeg %= 3600;
    minutos = tiempoSeg/60;
    segundos = tiempoSeg % 60;
}
void Hora::mostrarHora()
{
    cout<<"La hora es "<<horas<<":"<<minutos<<":"<<segundos<<endl;
}
int Hora::convHoraEnSeg()
{
    return horas*3600 + minutos*60 + segundos;

}
/******FUNCIONES DE SOBRECARGA DE OPERADORES*****/
//pre incremento
 Hora& Hora::operator++()
 {
     ++this->segundos;

     if(this->segundos>59)
     {
         this->segundos = 0;
         this->minutos ++;
         if(this->minutos>59)
         {
             this->minutos = 0;
             this->horas++;
             if(this->horas>24)
                this->horas = 1;

         }

     }

     return  *this;
 }
//pre decremento
 Hora& Hora::operator--()
 {
     --this->segundos;

     if(this->segundos<1)
     {
         this->segundos = 59;
         this->minutos--;
         if(this->minutos<1)
         {
             this->minutos = 59;
             this->horas--;
             if(this->horas<1)
             {
                 this->horas = 24;
             }
         }
     }
     return *this;
 }
 Hora Hora::operator++(int)
 {
     Hora temp = *this;
     this->segundos++;
     if(this->segundos>59)
     {
         this->segundos = 0;
         this->minutos ++;
         if(this->minutos>59)
         {
             this->minutos = 0;
             this->horas++;
             if(this->horas>24)
                this->horas = 1;

         }

     }
    return temp;
 }
Hora Hora::operator--(int)
{
    Hora temp = *this;
    this->segundos--;
    if(this->segundos<1)
     {
         this->segundos = 59;
         this->minutos--;
         if(this->minutos<1)
         {
             this->minutos = 59;
             this->horas--;
             if(this->horas<1)
             {
                 this->horas = 24;
             }
         }
     }
    return temp;
}
Hora& Hora::operator+=(int segundos)
{

     Hora HoraAsumar(segundos);//convierte los segundos en hora,minutos y segundos
     this->horas += HoraAsumar.horas;
     while(this->horas > 24)
         this->horas-=24;
     this->minutos += HoraAsumar.minutos;
     if(this->minutos > 59)
     {
        this->minutos -= 59;
        this->horas++;
     }
     this->segundos += HoraAsumar.segundos;
     if(this->segundos > 59)
     {
        this->segundos -= 59;
        this->minutos++;
     }
//    this->horas += segundos/3600;
//    segundos %=3600;
//    this->minutos += segundos/60;
//    this->segundos += segundos%60;
    return  *this;
}


Hora& Hora::operator-=(int segundos)
{
    Hora horasArestar(segundos);
    horasArestar.mostrarHora();
    this->horas -= horasArestar.horas;
    while(this->horas < 1 )
        this->horas += 24;
    this->minutos -= horasArestar.minutos;
    if(this->minutos < 1)
    {
    this->minutos += 59;
    this->horas--;
    }
    this->segundos-=horasArestar.segundos;
    if(this->segundos < 1)
    {
    this->segundos += 59;
    this->minutos--;
    }
    return *this;
}
/******FUNCIONES FRIENDS****/
Hora operator+(int segundos,const Hora& h2)
{
    Hora horSum = h2;
    horSum.segundos += segundos;
    return horSum;

}
/*****FUNCIONES GLOBALES****/
////istream& operator >>(istream& ent, Hora& h)
////{
////    int horas, minutos, segundos;
////    char c;
////
////    ent >> horas >> c >> minutos >> c >> segundos;
////
////    h.Hora(horas, minutos, segundos);
////
////    return ent;
////}
ostream& operator <<(ostream& sal, const Hora& hora)
{
    return sal << hora.horas << ':' << hora.minutos << ':' << hora.segundos;
}

// int Hora::sumarORestarSeg(int horaActualEnSeg,int segASumar)//sirve tanto para sumar como para rstar segundos
// {
//    return horaActualEnSeg+segASumar;
// }
//  void Hora::sumarUnSeg()
//  {
//      segundos++;
//      if(segundos==60)
//      {
//          minutos++;
//          segundos=0;
//      }
//
//  }
//void Hora::sumarHoras(Hora h1,Hora h2)
//  {
//
//  }
int main()
{
    Hora horaActual(24,58,58);
    Hora horaEnSeg(15600);
   // Hora defaulteada;
    //defaulteada += 3760;
    //horaActual.mostrarHora();
    //cout<< "La fecha suma es: " << defaulteada << endl;
    //salida<< "La fecha suma es: " << defaulteada << endl;
    cout << "la hora es : "<< horaEnSeg <<endl;

//    --horaActual;
//    horaActual.mostrarHora();
//    horaActual--;
//    horaActual.mostrarHora();
  //  horaActual += 20;
   // horaActual.mostrarHora();
    /*int horaActualEnseg;
    horaActualEnseg = horaActual.convHoraEnSeg();
    Hora horaSumada(horaSumada.sumarORestarSeg(horaActualEnseg,-125));//sumarSeg sirve tanto para sumar como para restar
    horaSumada.mostrarHora();
    horaActual.mostrarHora();
    horaEnSeg.mostrarHora();
    horaActual.sumarUnSeg();
    horaActual.mostrarHora();*/
   /* horaActual.sumarHoras();
    horaActual.mostrarHora();*/

    ;
    return 0;
}
