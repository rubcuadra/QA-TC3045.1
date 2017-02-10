#include "VideoJuego.h"
#include "Almacen.h"
#include "GameFactory.h"

int main()
{
    GameFactory* gf = new GameFactory();
    
    VideoJuego* v1 = gf->createGame("estrategia", VideoJuego::LUCHA, "primero", 1);
    Estrategia e = *(Estrategia*)v1;
    VideoJuego* v3 = gf->createGame("estrategia", VideoJuego::LUCHA, "tercero", 123);

    Almacen<VideoJuego> a;
    a.add(v1);
    a.add(&e);
    a.add(v3);
    
    delete gf;
    delete v1;
    delete v3;
    
}
