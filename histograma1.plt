f(x)=(0.25**x)/(1.25**(2+x))
plot  "histograma1.dat" using 1:2 title "L=64 y r=0.25" with linespoints,\
"histograma2.dat" using 1:2 title "L=1024 y r=0.25" with linespoints,\
f(x) title "Distribución teórica" with lines
set xlabel "Longitud de hueco"
set xrange [1:9]
set ylabel "Frecuencia"
set yrange [0:0.15]
set terminal png
set output "histograma_0.25.png"
replot
