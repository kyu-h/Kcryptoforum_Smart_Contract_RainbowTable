<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Page Title</title>
    <script type=”text/javascript” src=”web3.min.js”></script>
    <script type=”text/javascript” src=”eth.js”></script>
    <script src="https://cdn.jsdelivr.net/gh/ethereum/web3.js/dist/web3.min.js"></script>
    <script src="http://code.jquery.com/jquery-1.10.2.js"></script> <!-- jquery 사용하고 싶을 경우  import -->
</head>
<style>
    table, th, td {
        border: 1px solid black;
    }
</style>
<body>
    <p>Please click algorithm type and output bits</p>
    <script>
        var cookie = document.cookie;
        var split_cookie = cookie.split('/');
        var verify_num = 0;
        
        var algo = split_cookie[0];
        var bits = split_cookie[1];
        var input_text = split_cookie[2];
        var config = "";
        var text = "";
        
        console.log(cookie);
        console.log(input_text);
        
        if(split_cookie[0] == "LEA"){
            config = split_cookie[3];
            console.log(config);
        }
        
        if(algo == "LSH"){
            var findStr = "tt";
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + ".txt";
            
            document.writeln("<br /><br />");
            document.writeln("Original input file<br>");
            inputFile(input);
            
            var split_txt = text.split('/');
            
            for(var i =0; i<split_txt.length; i++){
                if(split_txt[i] == input_text){
                    document.writeln("<br />");
                    document.writeln(input_text + "is already exist");
                    
                    verify_num = 1;
                }
                
                if(split_txt[i].indexOf(findStr) != -1){
                    console.log(split_txt[i] + " find!!");
                }
            }
            
            
            if(verify_num == 0){
                NotExist();
                
                document.writeln("<br /><br />");
                document.writeln("Newest input file<br>");

                inputFile(input);
            }else {
                alert("You can not put new block");
            }
            
            $(window).ready(function(){
                console.log("load");

            });    
        }else if(algo == "LEA"){
            var findStr = "tt";
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + ".txt";
            
            document.writeln("<br /><br />");
            document.writeln("Original input file<br>");
            inputFile(input);
            
            var split_txt = text.split('/');
            
            for(var i =0; i<split_txt.length; i++){
                if(split_txt[i] == input_text){
                    document.writeln("<br />");
                    document.writeln(input_text + "is already exist");
                    
                    verify_num = 1;
                }
                
                if(split_txt[i].indexOf(findStr) != -1){
                    console.log(split_txt[i] + " find!!");
                }
            }
            
            
            if(verify_num == 0){
                NotExist();
                
                document.writeln("<br /><br />");
                document.writeln("Newest input file<br>");

                inputFile(input);
            }else {
                alert("You can not put new block");
            }
            
            $(window).ready(function(){
                console.log("load");

            });    
        }
        
        function inputFile(input){
            var fso = new ActiveXObject("Scripting.FileSystemObject");    
            var ForReading = 1;
            var f1 = fso.OpenTextFile(input, ForReading);
            text = f1.ReadAll();
            document.writeln(text);
            f1.close();
            return text;
        }
        
        
        function NotExist(){
            var fileObject = new ActiveXObject("Scripting.FileSystemObject");
            
            if(algo == "LSH"){
                fWrite = fileObject.CreateTextFile("C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + ".txt", true);    
            }else if(algo == "LEA"){
                fWrite = fileObject.CreateTextFile("C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + ".txt", true);    
            }

            for(var i=0; i<split_txt.length; i++){
                fWrite.write(split_txt[i]);
                fWrite.write("/");
            }
            
            fWrite.write(input_text);

            fWrite.close();
        }
    </script>
</body>
</html>
