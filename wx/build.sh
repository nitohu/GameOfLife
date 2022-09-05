out=( main )
files=( ../lib/board.cpp GameButton.cpp GOLWindow.cpp GOLApp.cpp main.cpp )

for file in ${files[@]}; do
    echo "Creating binaries for $file..."
    g++ -c `wx-config --cxxflags` -std=c++17 $file
done

echo "Compiling binaries..."
g++ -o $out *.o `wx-config --libs` -std=c++17
rm *.o
