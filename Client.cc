  #include "Client.hh"
  
  Client::Client();
  
  
  
  Client::Client(int torn, int caixa, int producte, Rellotge R);
  
  
  Client::~Client();

   
   void Client::afegir_torn(int t);
    torn = t;

   void Client::afegir_caixa(int c);
    caixa = c;
  
   void Client::modificar_caixa(int caixa); // un cop assignada una caixa dubto que la canviem
   
   void Client::afegir_producte(int producte);
   
   int Client::consultar_torn(int torn) const;
    return torn;
   
   int Client::consultar_caixa(int caixa);
    return caixa;
   
   Rellotge Client::consulta_hora(Rellotge R) const;
    return R;
