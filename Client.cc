  Client::Client();
  
  
  
  Client::Client(int torn, int caixa, int producte, Rellotge R);
  
  
  Client::~Client();

   
   void Client::afegir_torn(int torn);
  

   void Client::afegir_caixa(int caixa);
  
   void Client::modificar_caixa(int caixa);
   
   void Client::afegir_producte(int producte);
   
   int Client::consultar_torn(int torn) const;
   
   int Client::consultar_caixa(int caixa);
   
   Rellotge Client::consulta_hora(Rellotge R) const;
