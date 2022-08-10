class Board {
protected:
    int w, h;
    int generation;
    bool *board;
    bool running;

    void initializeBoard();

    int getNeighborCells(int cell, bool *b);
    void updateCell(bool* cell, int neighborCount);

public:
    Board();
    Board(int w, int h);

    virtual ~Board();

    bool isRunning();
    int getGeneration();

    void setSize(int w, int h);
    virtual void toggleCell(unsigned int pos);

    virtual void printBoard(bool showPos);
    virtual void update();
};
