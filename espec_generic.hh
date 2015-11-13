CLASSES:

        CLIENT:
        int numero de torn
        int caixa on ha d'anar
        rellotge temps del rellotge
        map<producte,int> //Contçe els productes i les seves quantitats
        -
        funcions:
                /* No cal necessariament */
                int nombre_productes();
                /** @brief consulta i retorna el nombre de productes del
                        client
                \pre El client existeix i el te productes assignats
                \post Retorna el nombre[enter] de productes

        CAIXES:
        -int/bool tipus de caixa(tancada, rapida o normal)


        SUPERMERCAT:
        int nombre rengles (entre 1-26 aka A-Z)
        int nombre columnes(entre 1-9)
        int nombre caixes(1-20)
        

        PRODUCTE:
        string nom
        string seccio(lletra i numero)
        double preu(decimals)   
        int temps_cobrament(tc>0)
                


        (RELLOTGE)
