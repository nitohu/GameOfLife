class Board {
protected:
    int w, h;
    int *board;

    void initializeBoard();

public:
    Board();
    Board(int w, int h);

    virtual ~Board();

    void setSize(int w, int h);
    virtual void printBoard();
};
