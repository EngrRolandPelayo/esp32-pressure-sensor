const String javascript PROGMEM = R"(
  $(document).ready(function(){
    setInterval(getData,1000);
    function getData(){ 
      $.ajax({ 
        type:"GET", 
        url:"data", 
        success: function(data){ 
          var s = data; 
          $('#pressure-value').val(s); 
        } 
      }).done(function() { 
        console.log('ok'); 
      })
    }
   });
)";
