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
    <script>
        var cookie = document.cookie;
        var split_cookie = cookie.split('/');
        var verify_num = 0;
        
        var algo = split_cookie[0];
        var bits = split_cookie[1];
        var input_text = "";
        var config = "";
        var LEA_plain = "";
        var LEA_key = "";
        var LEA_conf = "";
        var text = "";
        
        var split_LEA = "";
        var split_PlaintText = "";
        var split_Key = "";
        var split_conf = "";
        
        console.log(cookie);
        
        if(split_cookie[0] == "LEA"){
            config = split_cookie[2];
            LEA_plain = split_cookie[3];
            LEA_key = split_cookie[4];
            LEA_conf = split_cookie[5];
            console.log(config);
            console.log(LEA_conf);
        }else if(split_cookie[0] == "LSH"){
            input_text = split_cookie[2];
            console.log(input_text);
        }
        
        if(algo == "LSH"){
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + ".txt";
            
            document.writeln("Original input file<br>");
            inputFile(input);
            
            var split_txt = text.split('"\r\n"');
            var first_split = split_txt[0].split('"');
            split_txt[0] = first_split[1];
            var final_split = split_txt[split_txt.length - 1].split('"');
            split_txt[split_txt.length - 1] = final_split[0];
            
            
            for(var i =0; i<split_txt.length; i++){
                if(split_txt[i] == input_text){
                    document.writeln("<br />");
                    document.writeln(input_text + "is already exist");
                    
                    verify_num = 1;
                }
            }
            
            
            if(verify_num == 0){
                NotExist();
                
                document.writeln("<br /><br />");
                document.writeln("Newest input file<br>");

                inputFile(input);
                
                
            <?php
                $current = "";
                $answer = "";

                putenv("PATH=C:\\Program Files (x86)\\mingw-w64\\i686-7.3.0-posix-dwarf-rt_v5-rev0\\mingw32\\bin");

                shell_exec("gcc -c main.c");
                shell_exec("gcc -c lsh.c");
                shell_exec("gcc -c lsh256.c");
                shell_exec("gcc -c lsh512.c");

                shell_exec("gcc -o main.exe main.o lsh.o lsh256.o lsh512.o");

                $answer = shell_exec("main.exe");
            ?>
                
            }else {
                alert("You can not put new block");
            }


        }else if(algo == "LEA"){
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + ".txt";
            document.writeln("Original input file<br>");
            inputFile(input);
            
            var conf = "";
            
            if(config == "CTR"){
                conf = "CTR";
            }else if(config == "CBC"){
                conf = "IV";
            }
            
            if(config == "ECB"){
                split_LEA = text.split('Key');
                split_PlaintText = split_LEA[0].split('"\r\n"');

                var first_PlainText = split_PlaintText[0].split('"');
                split_PlaintText[0] = first_PlainText[1];
                var final_PlainText = split_PlaintText[split_PlaintText.length - 1].split('"');
                split_PlaintText[split_PlaintText.length - 1] = final_PlainText[0];
                
                split_Key = split_LEA[1].split('"\r\n"');
                var first_Key = split_Key[0].split('"');
                split_Key[0] = first_Key[1];
                var final_Key = split_Key[split_Key.length - 1].split('"');
                split_Key[split_Key.length - 1] = final_Key[0];

            }else if(config != "ECB"){
                if(config == "CTR"){
                    split_LEA = text.split(conf + " =");    
                }else if (config == "CBC"){
                    split_LEA = text.split(conf);    
                }
                
                split_PlaintText = split_LEA[0].split('"\r\n"');
                
                var first_PlainText = split_PlaintText[0].split('"');
                split_PlaintText[0] = first_PlainText[1];
                var final_PlainText = split_PlaintText[split_PlaintText.length - 1].split('"');
                split_PlaintText[split_PlaintText.length - 1] = final_PlainText[0];
                
                var split_LEA2 = split_LEA[1].split("Key");
                split_conf = split_LEA2[0].split('"\r\n"');
                
                var first_split = split_conf[0].split('"');
                split_conf[0] = first_split[1];
                var final_split = split_conf[split_conf.length - 1].split('"');
                split_conf[split_conf.length - 1] = final_split[0];
                
                split_Key = split_LEA2[1].split('"\r\n"');
                var first_Key = split_Key[0].split('"');
                split_Key[0] = first_Key[1];
                var final_Key = split_Key[split_Key.length - 1].split('"');
                split_Key[split_Key.length - 1] = final_Key[0];
            }

            NotExist();

            document.writeln("<br /><br />");
            document.writeln("Newest input file<br>");
            inputFile(input);
            
            
            <?php
                $current = "";
                $answer = "";

                putenv("PATH=C:\\Program Files (x86)\\mingw-w64\\i686-7.3.0-posix-dwarf-rt_v5-rev0\\mingw32\\bin");

                shell_exec("gcc -c LEA_Main.c");
                shell_exec("gcc -c LEA_Default.c");
                shell_exec("gcc -c LEA_ConfigMode.c");

                shell_exec("gcc -o LEA_Main.exe LEA_Main.o LEA_Default.o LEA_ConfigMode.o");

                $answer = shell_exec("LEA_Main.exe");
            ?>
        }
        
        function a2hex(str) {
            var arr = [];
            for (var i = 0, l = str.length; i < l; i ++) {
                var hex = Number(str.charCodeAt(i)).toString(16);
                arr.push(hex);
            }
            return arr.join('');
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
                
                fWrite.write("Algo_ID = LSH-" + bits);
                fWrite.write("\r\n");
                
                var count = split_txt.length + 1;
                
                fWrite.write("Message = " + count);
                fWrite.write("\r\n");
                
                for(var i=0; i<split_txt.length; i++){
                    fWrite.write('"' + split_txt[i] + '"');
                    fWrite.write("\r\n");
                }

                fWrite.write('"' + input_text + '"');
                
            }else if(algo == "LEA"){
                fWrite = fileObject.CreateTextFile("C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + ".txt", true);    
                
                fWrite.write("Algo_ID = LEA_" + config + "-" + bits);
                fWrite.write("\r\n");
                
                var PlainText = new Array();
                var Key = new Array();
                var conf = new Array();
                var full_plain = '"';
                var full_key = '"';
                var full_conf = '"';
                var Plain_length = LEA_plain.length;
                var Key_length = LEA_key.length;
                var Config_length = LEA_conf.length;
                var Plain_size = 0;
                var Key_size = 0;
                var count = 0;
                var config_mode = "";
                var config_mode_size = 16;
                
                if(bits == "128"){
                    Key_size = 16;
                }else if(bits == "192"){
                    Key_size = 24;
                }else {
                    Key_size = 32;
                }
                
                if(config == "ECB"){
                    Plain_size = 16;
                }else if(config == "CBC"){
                    Plain_size = 64;
                    config_mode = "IV";
                }else if(config == "CTR"){
                    Plain_size = 64;
                    config_mode = "CTR";
                }
                
                console.log("Length: " + Plain_length);
                
                if(Plain_length == Plain_size){
                    for(var i=0; i<Plain_length; i++){
                        PlainText[i] = a2hex(LEA_plain[i]);

                        if(i != Plain_length - 1){
                            full_plain += PlainText[i] + ", ";    
                        }else if(i == length - 1){
                            full_plain += PlainText[i] + '"';
                        }
                    }
                }else {
                    for(var i=0; i<Plain_size; i++){
                        if(i < Plain_length){
                            PlainText[i] = a2hex(LEA_plain[i]);

                            full_plain += PlainText[i] + ", ";
                        }else {
                            PlainText[i] = "00";

                            if(i == Plain_size - 1){
                                full_plain += PlainText[i] + '"';
                            }else {
                                full_plain += PlainText[i] + ", ";
                            }
                        }
                    }
                }

                count = split_PlaintText.length + 1;

                fWrite.write("PlainText = " + count +  "\r\n");

                for(var i=0; i<split_PlaintText.length; i++){
                    fWrite.write('"' + split_PlaintText[i] + '"');
                    fWrite.write("\r\n");
                }

                fWrite.write(full_plain);
                
                if(config != "ECB"){
                    if(Config_length == config_mode_size){
                        for(var i=0; i<Config_length; i++){
                            conf[i] = a2hex(LEA_conf[i]);

                            if(i != Config_length - 1){
                                full_conf += conf[i] + ", ";    
                            }else if(i == Config_length - 1){
                                full_conf += conf[i] + '"';
                            }
                        }
                    }else {
                        for(var i=0; i<config_mode_size; i++){
                            if(i < Config_length){
                                conf[i] = a2hex(LEA_conf[i]);

                                full_conf += conf[i] + ", ";
                            }else {
                                conf[i] = "00";

                                if(i == config_mode_size-1){
                                    full_conf += conf[i] + '"';
                                }else {
                                    full_conf += conf[i] + ", ";
                                }
                            }
                        }
                    }

                    count = split_conf.length + 1;

                    fWrite.write("\r\n" + config_mode + " = " + count + "\r\n");

                    for(var i=0; i<split_conf.length; i++){
                        fWrite.write('"' + split_conf[i] + '"');
                        fWrite.write("\r\n");
                    }

                    console.log(full_conf);
                    fWrite.write(full_conf);
                }
                
                console.log("Length: " + Key_length);

                if(Key_length == Key_size){
                    for(var i=0; i<Key_length; i++){
                        Key[i] = a2hex(LEA_key[i]);

                        if(i != Key_length - 1){
                            full_key += Key[i] + ", ";    
                        }else if(i == Key_length - 1){
                            full_key += Key[i] + '"';
                        }
                    }
                }else {
                    for(var i=0; i<Key_size; i++){
                        if(i < Key_length){
                            Key[i] = a2hex(LEA_key[i]);

                            full_key += Key[i] + ", ";
                        }else {
                            Key[i] = "00";

                            if(i == Key_size-1){
                                full_key += Key[i] + '"';
                            }else {
                                full_key += Key[i] + ", ";
                            }
                        }
                    }
                }

                count = split_Key.length + 1;

                fWrite.write("\r\n" + "Key = " + count + "\r\n");

                for(var i=0; i<split_Key.length; i++){
                    fWrite.write('"' + split_Key[i] + '"');
                    fWrite.write("\r\n");
                }

                fWrite.write(full_key);
            }

            fWrite.close();
        }
        
        function checkall(){
            
            console.log("gogo");
            window.location.href = "/SmartContract_RainbowTable/Kcryptoforum_Smart_Contract_RainbowTable/dapp/checkall.php";
        }
    </script>

    <br><br>
    <div id="check" style="display: block;">
        <input type = "button" id="button" value="CheckAll" onclick="checkall()">
    </div>
</body>
</html>
