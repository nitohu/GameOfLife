class Board {
protected:
    int w, h;
    bool *board;
    bool running;

    void initializeBoard();

    void getNeighborCells(int cell, int *r);

public:
    Board();
    Board(int w, int h);

    virtual ~Board();

    bool isRunning();

    void setSize(int w, int h);
    virtual void toggleCell(unsigned int pos);

    virtual void printBoard(bool showPos);
    virtual void update();
};
