$(document).on('keydown', function(event) {  
    switch(event.which){
        case 38:
            $("#adelante").click();
            break;
        
        case 37:
            $("#izquierda").click();
            break;

        case 39:
            $("#derecha").click();
            break;
        
        case 40:
            $("#atras").click(); 
            break;

        case 32:
            $("#parar").click();
            break; 

        case 16:
            $("#rapido").click();
            break; 
    }
    
    
  }); 