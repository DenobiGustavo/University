document.getElementById('uploadInput').addEventListener('change', exibirImagemSelecionada);

var zoomLevel = 1.0;
var minZoomLevel = 0.5;
var maxZoomLevel = 4.0;

var imageContainer = document.getElementById('imageContainer');
var isDragging = false;


imageContainer.addEventListener('wheel', function(e) {
  e.preventDefault();

  const deltaY = e.deltaY;
  const zoomSpeed = 0.1;

  if (deltaY > 0) {
    // Scroll para baixo - diminui o zoom
    zoomLevel -= zoomSpeed;
  } else {
    // Scroll para cima - aumenta o zoom
    zoomLevel += zoomSpeed;
  }

  zoomLevel = Math.max(minZoomLevel, Math.min(maxZoomLevel, zoomLevel)); // entender um pouco melhor

  imageContainer.style.transform = `scale(${zoomLevel})`; //entender um pouco melhor
});



function exibirImagemSelecionada(evento) {
  var arquivo = evento.target.files[0];
  var leitor = new FileReader();

  leitor.onload = function(evento) {
    imageContainer.style.backgroundImage = "url(" + evento.target.result + ")";
    
    var imagem = new Image();
    imagem.onload = function() {
      var canvas = document.createElement('canvas');
      var contexto = canvas.getContext('2d');
      
      // Defina o tamanho do canvas como o tamanho real da imagem
      canvas.width = imagem.width;
      canvas.height = imagem.height;
      
      contexto.drawImage(imagem, 0, 0);
      
      var dadosImagem = contexto.getImageData(0, 0, canvas.width, canvas.height).data;
      var somaVermelho = 0;
      var somaVerde = 0;
      var somaAzul = 0;
      var quantidadePixels = dadosImagem.length / 4;
      
      for (var i = 0; i < dadosImagem.length; i += 4) {
        somaVermelho += dadosImagem[i];
        somaVerde += dadosImagem[i + 1];
        somaAzul += dadosImagem[i + 2];
      }
      
      var mediaVermelho = Math.round(somaVermelho / quantidadePixels);
      var mediaVerde = Math.round(somaVerde / quantidadePixels);
      var mediaAzul = Math.round(somaAzul / quantidadePixels);
      
      var corMedia = 'rgb(' + mediaVermelho + ', ' + mediaVerde + ', ' + mediaAzul + ')';
      
      var retangulo = document.createElement('div');
      retangulo.style.backgroundColor = corMedia;
      retangulo.style.width = '140px';
      retangulo.style.height = '60px';
      retangulo.style.position = 'center';
      retangulo.style.top = '10px';
      retangulo.style.left = '10px';
      
      var texto = document.createElement('p');
      texto.textContent = "Média RGB: " + mediaVermelho + ", " + mediaVerde + ", " + mediaAzul;
      texto.style.color = '#ffffff';
      texto.style.margin = '10px';
      
      var container = document.getElementById('averageColorRectangle');
      container.innerHTML = '';
      container.appendChild(retangulo);
      retangulo.appendChild(texto);
    };

    imagem.src = evento.target.result;
  };

  leitor.readAsDataURL(arquivo);
}