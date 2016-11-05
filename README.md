Rozszerzony problem producenta i konsumenta
=======================

Tomasz Nanowski 

Wojciech Pratkowiecki

Systemy Operacyjne - P1 - semestr zimowy 2016/17

----------

Opis problemu
-------------

Podstawowy model problemu producenta i konsumenta opiera się na dwóch rodzajach procesów - producencie i konsumencie. Producent wytwarza określony produkt, który następnie jest konsumowany przez konsumenta. Łącznikiem pomiędzy nimi jest bufor mogący pomieścić określoną ilość jednostek. Jeżeli bufor jest pusty konsument musi zaczekać na pojawienie się nowych produktów. W sytuacji przepełnionego bufora to producent musi zawiesić swoją pracę do momentu pobrania produktów od konsumenta. Problemem synchronizacji jest doprowadzenie do sytuacji, kiedy żadna z powyższych sytuacji nie nastąpi.

Rozszerzenie problemu
----------------------------------

Model rozszerzony problemu będzie polegał na relacji: jeden producent - wielu konsumentów. W tym przypadku pojawiają się nowe problemy utrudniające efetywną implementację. Skoro mamy na jeden bufor wielu konsumentów należy unikać sytuacji, w której o zasoby starają się da osobne procesy-konsumenci. Nie chcielibyśmy również, aby aktywnych było więcej procesów-konsumentów niż ilość gotowych produktów w buforze. W tym celu należy utworzyć nowy wątek odpowiedzialny za aktywność konsumentów. Wątek ten trzyma uśpionych konsumentów w kolejce. Kiedy w buforze pojawia się produkt budzi on konsumenta i każe mu odebrać zasoby. Następnie proces-konsument wraca do wątku zarządzającego, który to przydziela mu kolejne zadanie lub usypia i dodaje do koleki.

Praktyczne uzasadnienie problemu
----------------------------------
