#ifndef ENTITIES_H
#define ENTITIES_H

class Entities {
  protected:
    int posX;
    int posY;
  
  public:
    Entities();
    Entities(int x, int y);
    Entities(const Entities& other);
    ~Entities();

    Entities& operator=(const Entities& other);

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    virtual void move(int x, int y);
};

#endif