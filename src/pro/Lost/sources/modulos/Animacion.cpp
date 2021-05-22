#include "Animacion.h"

Animacion::Animacion(){
    //Constructor por defecto
}

Animacion::Animacion(string textura, int tamano, float vel){
    
    if(!texture.loadFromFile(textura)){
        cout << "No se ha podido cargar la textura (animacion)" << endl;
    }

    velAnim = vel;
    size = tamano;
}

void Animacion::colocarFrames(IntRect primero, IntRect ultimo){
    primFr = primero;
    ultFr = ultimo;
    miFrame = primero;

    sprite = Sprite(texture, miFrame);
    // sprite.setOrigin(size/2, size/2);
    sprite.setScale(0.50, 0.50);
}

void Animacion::update(){
    float tiempo_pasado = clock.getElapsedTime().asSeconds();

    if(tiempo_pasado >= velAnim && animar){
        clock.restart();

        if(miFrame.left == ultFr.left){
            miFrame.left = primFr.left;
        }else{
            miFrame.left += size;
        }

        sprite.setTextureRect(miFrame);
    }
}

void Animacion::update(float deltaTime, Vector2f movimiento){
    float tiempo_pasado = clock.getElapsedTime().asSeconds();

    if(tiempo_pasado >= velAnim && animar){
        clock.restart();

        if(miFrame.left == ultFr.left){
            miFrame.left = primFr.left;
        }else{
            miFrame.left += size;
        }

        sprite.setTextureRect(miFrame);
    }

    sprite.move(movimiento*deltaTime);
}

void Animacion::setPos(Vector2f v){
    sprite.setPosition(v);
}

void Animacion::rotateSprite(float r)
{
    sprite.setRotation(r);
    rotacion = r;
}

void Animacion::Draw(RenderWindow &window){
    window.draw(sprite);
}

void Animacion::Stop(){
    animar = false;
}

void Animacion::Play(){
    animar = true;
}

void Animacion::changeSize(float x, float y){
    sprite.setScale(x,y);
}

void Animacion::setTextura(Texture t){
    sprite = Sprite(t);
}