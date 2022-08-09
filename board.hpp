class Board {
protected:
    int w, h;
    bool *board;

    void initializeBoard();

public:
    Board();
    Board(int w, int h);

    virtual ~Board();

    void setSize(int w, int h);
    virtual void toggleCell(unsigned int pos);

    virtual void printBoard(bool showPos);
    virtual void update();
};
