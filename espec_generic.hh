CLASSES:

        class client{
        
        int numero //numero de torn
        int caixa //caixa on ha danar
        int qunitats // quantitat d'unitats total
        rellotge //temps del rellotge
        map<producte,int> //Conte els productes i les seves quantitats
        
        -
        funcions:
                /* No cal necessariament */
                int quantitat_unitats();
                /** @brief consulta i retorna el nombre d'unitats de
                 * productes del client
                \pre El client existeix i te productes assignats
               \post Retorna el nombre[enter] d'unitats de productes
                */

        }
        
        CAIXES:
        -int/bool tipus de caixa(tancada, rapida o normal)


        class supermercat{
        int rengles // (entre 1-26 aka A-Z)
        int columnes //(entre 1-9)
        int caixes //(1-20)
        }

        PRODUCTE:
        string nom
        string seccio //(lletra i numero)
        double preu //(decimals)   
        int temps_cobrament //(tc>0)
                


        (RELLOTGE)
