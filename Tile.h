
class Tile
{
public:
    enum COLORS
    {
        BLACK, BLUE, GREEN, CYAN,
        RED, MAGENTA, BROWN, LIGHTGRAY,
        DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
        LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
    };
    Tile();
    ~Tile();
    void setColor(COLORS color);
    void setValue(int value);
    void setLength(int length);
    void setAll(int value);
    COLORS getColor();
    int getValue();
    int getLength();
    Tile& operator+=(const Tile& other);

protected:

private:
    COLORS color;
    int value;
    int length;

};
