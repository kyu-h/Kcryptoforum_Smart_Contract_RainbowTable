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
    <table style="">
      <tr>
        <th>Algorithm types</th>
        <th>Output Bits</th>  
      </tr>
      <tr>
        <td>
            <input type="radio" name="algo" value="LSH"> LSH<br>
            <input type="radio" name="algo" value="LEA"> LEA<br>
            <input type="radio" name="algo" value="HIGHT"> HIGHT<br>
            <input type="radio" name="algo" value="CHAM"> CHAM<br>
        </td>

        <td>
            <div id="POP_LSH">
                <input type="radio" name="bits" value="256_224"> 256_224<br>
                <input type="radio" name="bits" value="256_256"> 256_256<br>
                <input type="radio" name="bits" value="512_224"> 512_224<br>
                <input type="radio" name="bits" value="512_256"> 512_256<br>
                <input type="radio" name="bits" value="512_384"> 512_384<br>
                <input type="radio" name="bits" value="512_512"> 512_512
            </div>

            <div id="POP_LEA" style="display: none;">
                <input type="radio" name="bits" value="128"> 128<br>
                <input type="radio" name="bits" value="192"> 192<br>
                <input type="radio" name="bits" value="256"> 256
            </div>
        </td>  
      </tr>
    </table>
    <div id="LEA_Config" style="display: none;">
        <table>
            <th>Config Mode</th>
            <td>
                <input type="radio" name="config" value="ECB"> ECB<br>
                <input type="radio" name="config" value="CBC"> CBC<br>
                <input type="radio" name="config" value="CTR"> CTR
            </td>
        </table>
    </div>
    
    <br><br>
    
    <div id="bits_128" style="display: none;">
        <p>You clicked output bits for 128, PlainText size is 16, Key size is 16. If you not put full length of PlainText or Key, the rest of the value will be filled with '0'.</p>
    </div>
    <div id="bits_192" style="display: none;">
        <p>You clicked output bits for 192, PlainText size is 16, Key size is 24. If you not put full length of PlainText or Key, the rest of the value will be filled with '0'.</p>
    </div>
    <div id="bits_256" style="display: none;">
        <p>You clicked output bits for 256, PlainText size is 16, Key size is 32. If you not put full length of PlainText or Key, the rest of the value will be filled with '0'.</p>
    </div>
    
    <div id="POP_LEA" style="display: block;">
        <input type="radio" name="values" value="INPUT"> INPUT<br>
        <input type="radio" name="values" value="SEARCH"> SEARCH
    </div>
    
    <div id="LSH" style="display: block;">
        <div id="LSH_Verify" style="display: none;">
            Input values : <input type="text" name="input_text" id="input_text">
            <input type = "button" id="button1" value="verify" onclick="verify()">
        </div>

        <div id="LSH_Search" style="display: none;">
            Search values : <input type="text" name="input_text2" id="input_text2">
            <input type = "button" id="button2" value="Search" onclick="Search()">
        </div>
    </div>
    
    <div id="LEA" style="display: none;">        
        <div id="LEA_Verify" style="display: none;">
            PlainText values : <input type="text" name="input_text3" id="input_text3"> <br>
            Key values : <input type="text" name="input_text4" id="input_text4">
            <input type = "button" id="button3" value="verify" onclick="verify()">
        </div>
        
        <div id="LEA_Verify_CBC" style="display: none;">
            PlainText values : <input type="text" name="verify_plain_cbc" id="verify_plain_cbc"> <br>
            IV : <input type="text" name="verify_IV_cbc" id="verify_IV_cbc"> <br>
            Key values : <input type="text" name="verify_key_cbc" id="verify_key_cbc">
            <input type = "button" id="button3" value="verify" onclick="verify()">
        </div>
        
        <div id="LEA_Verify_CTR" style="display: none;">
            PlainText values : <input type="text" name="verify_plain_ctr" id="verify_plain_ctr"> <br>
            CTR : <input type="text" name="verify_ctr_ctr" id="verify_ctr_ctr"> <br>
            Key values : <input type="text" name="verify_key_ctr" id="verify_key_ctr">
            <input type = "button" id="button3" value="verify" onclick="verify()">
        </div>

        <div id="LEA_Search" style="display: none;">
            PlainText values : <input type="text" name="input_text5" id="input_text5"> <br>
            Key values : <input type="text" name="input_text6" id="input_text6">
            <input type = "button" id="button4" value="Search" onclick="Search()">
        </div>
        
        <div id="LEA_Search_CBC" style="display: none;">
            PlainText values : <input type="text" name="input_text3" id="input_text5"> <br>
            IV : <input type="text" name="input_text4" id="input_IV"> <br>
            Key values : <input type="text" name="input_text4" id="input_text6">
            <input type = "button" id="button4" value="Search" onclick="Search()">
        </div>
        
        <div id="LEA_Search_CTR" style="display: none;">
            PlainText values : <input type="text" name="input_text3" id="input_text5"> <br>
            CTR : <input type="text" name="input_text4" id="input_CTR"> <br>
            Key values : <input type="text" name="input_text4" id="input_text6">
            <input type = "button" id="button4" value="Search" onclick="Search()">
        </div>
    </div>
    
    

    <br><br>
    
    <!--<script>
        if (typeof web3 !== 'undefined') {
          web3 = new Web3(web3.currentProvider);
        } else {
          // set the provider you want from Web3.providers
          web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
        }
        
        var network_version = web3.version.network;
        console.log(network_version);
        
        var accounts = web3.eth.accounts;  //get account info
        var from_account = accounts[0];
        var to_account = accounts[1];
        
        var coinbase = web3.eth.coinbase;
        var balance = web3.fromWei(web3.eth.getBalance(coinbase), 'ether');
        
        console.log(coinbase);
        console.log(balance.c); //check ether in the coinbase 
        
        console.log(from_account);
        console.log(to_account);
        
        var transactionObj = { //transaction object setting
            from: from_account,
            to:to_account,
            value: 10000000
        };
        
        //web3.eth.sendTransaction(transactionObj);
    </script>-->
    
    <script>
        var get_cookie = document.cookie;
        var split_cookie = get_cookie.split('/');
        var algo = split_cookie[0];
        console.log(algo);
        
        if(algo == 'LEA'){
            console.log(algo+"!!!");
            window.onload = function() {
                $("input:radio[name='algo']:radio[value='LEA']").prop("checked", true);
                $("input:radio[name='algo']:radio[value='LSH']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='HIGHT']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='CHAM']").prop("checked", false);
                
                $('#POP_LSH').css('display', 'none');
                $('#POP_LEA').css('display', 'block');
                
                $('#LSH').css('display', 'none');
                $('#LEA').css('display', 'block');
                
                $('#LEA_Config').css('display', 'block');
            }
        }else if(algo == "LSH"){
            console.log(algo+"!!!");
            window.onload = function() {
                $("input:radio[name='algo']:radio[value='LEA']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='LSH']").prop("checked", true);
                $("input:radio[name='algo']:radio[value='HIGHT']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='CHAM']").prop("checked", false);
                
                $('#POP_LSH').css('display', 'block');
                $('#POP_LEA').css('display', 'none');
                
                $('#LSH').css('display', 'block');
                $('#LEA').css('display', 'none');
                
                $('#LEA_Config').css('display', 'none');
            }
        }
        
        function verify(){
            var AlgoradioVal = $(':radio[name="algo"]:checked').val();
            var BitsradioVal = $(':radio[name="bits"]:checked').val();
            var config_mode = $(':radio[name="config"]:checked').val();
            var input_text = $('input[name=input_text]').val();
            
            var Plain = "";
            var Key = "";
            
            var conf_CTR = "";
            var conf_IV = "";
            
            if(config_mode == "ECB"){
                Plain = $('input[name=input_text3]').val();
                Key = $('input[name=input_text4]').val();
            }else if(config_mode == "CBC"){
                Plain = $('input[name=verify_plain_cbc]').val();
                Key = $('input[name=verify_key_cbc]').val();
                conf_IV = $('input[name=verify_IV_cbc]').val();
            }else if(config_mode == "CTR"){
                Plain = $('input[name=verify_plain_ctr]').val();
                Key = $('input[name=verify_key_ctr]').val();
                conf_CTR = $('input[name=verify_ctr_ctr]').val();
            }
            
            var send_cookie = AlgoradioVal + "/" + BitsradioVal;
            
            if(AlgoradioVal == "LEA"){
                send_cookie += "/" + config_mode + "/" + Plain + "/" + Key;
                
                if(config_mode == "CBC"){
                    send_cookie += "/" + conf_IV; 
                }else if(config_mode == "CTR"){
                    send_cookie += "/" + conf_CTR; 
                }
            }else if(AlgoradioVal == "LSH"){
                send_cookie += "/" + input_text;
            }
            
            document.cookie = send_cookie;
            
            window.location.href = "/SmartContract_RainbowTable/Kcryptoforum_Smart_Contract_RainbowTable/dapp/verify.php";
        }
        
        function Search(){
            var AlgoradioVal = $(':radio[name="algo"]:checked').val();
            var BitsradioVal = $(':radio[name="bits"]:checked').val();
            var config_mode = $(':radio[name="config"]:checked').val();
            var input_text = $('input[name=input_text2]').val();
            var Plain = $('input[name=input_text5]').val();
            var Key = $('input[name=input_text6]').val();
            
            var send_cookie = AlgoradioVal + "/" + BitsradioVal;
            
            if(AlgoradioVal == "LEA"){
                send_cookie  += "/" + config_mode + "/" + Plain + "/" + Key;
            }else if(AlgoradioVal == "LSH"){
                send_cookie += "/" + input_text;
            }
            
            document.cookie = send_cookie;
            
            var r = confirm("If you click 'OK' you will pay for searching!");
            if (r == true) {
                window.location.href = "/SmartContract_RainbowTable/Kcryptoforum_Smart_Contract_RainbowTable/dapp/search.php";
            } else {
                window.location.href = "/SmartContract_RainbowTable/Kcryptoforum_Smart_Contract_RainbowTable/dapp/test.php";
            }
        }
        
        $('input[type=radio][name=algo]').on('click', function() {
            var chkvalue = $('input[type=radio][name=algo]:checked').val();
            console.log(chkvalue);

            if (chkvalue == 'LSH'){
                $('#POP_LSH').css('display', 'block');
                $('#POP_LEA').css('display', 'none');
                
                $('#uploadForm_LSH').css('display', 'block');
                $('#uploadForm_LEA').css('display', 'none');
                
                $('#LSH').css('display', 'block');
                $('#LEA').css('display', 'none');
                
                $('#LEA_Config').css('display', 'none');
            }else if(chkvalue == 'LEA'){
                $('#POP_LSH').css('display', 'none');
                $('#POP_LEA').css('display', 'block');
                
                $('#uploadForm_LSH').css('display', 'none');
                $('#uploadForm_LEA').css('display', 'block');
                
                $('#LSH').css('display', 'none');
                $('#LEA').css('display', 'block');
                
                $('#LEA_Config').css('display', 'block');
            }else if(chkvalue == 'HIGHT'){
                $('#POP_LSH').css('display', 'block');
                $('#POP_LEA').css('display', 'none');
                
                $('#uploadForm_LSH').css('display', 'block');
                $('#uploadForm_LEA').css('display', 'none');
                
                $('#LEA_Config').css('display', 'none');
            }else if(chkvalue == 'CHAM'){
                $('#POP_LSH').css('display', 'block');
                $('#POP_LEA').css('display', 'none');
                
                $('#uploadForm_LSH').css('display', 'block');
                $('#uploadForm_LEA').css('display', 'none');
                
                $('#LEA_Config').css('display', 'none');
            }
            
            if(chkbits == "128"){
                $('#bits_128').css('display', 'block');
                $('#bits_192').css('display', 'none');
                $('#bits_256').css('display', 'none');
            }else if(chkbits == "192"){
                $('#bits_128').css('display', 'none');
                $('#bits_192').css('display', 'block');
                $('#bits_256').css('display', 'none');
            }else if(chkbits == "256"){
                $('#bits_128').css('display', 'none');
                $('#bits_192').css('display', 'none');
                $('#bits_256').css('display', 'block');
            }
        });
        
        $('input[type=radio][name=bits]').on('click', function() {
            var chkbits = $('input[type=radio][name=bits]:checked').val();
            console.log(chkbits);

            if(chkbits == "128"){
                $('#bits_128').css('display', 'block');
                $('#bits_192').css('display', 'none');
                $('#bits_256').css('display', 'none');
            }else if(chkbits == "192"){
                $('#bits_128').css('display', 'none');
                $('#bits_192').css('display', 'block');
                $('#bits_256').css('display', 'none');
            }else if(chkbits == "256"){
                $('#bits_128').css('display', 'none');
                $('#bits_192').css('display', 'none');
                $('#bits_256').css('display', 'block');
            }
        });
    
        var conf = ""
        
        $('input[type=radio][name=config]').on('click', function() {
            var chkvalue = $('input[type=radio][name=config]:checked').val();

            conf = chkvalue;
            console.log(conf);
        });
        
        $('input[type=radio][name=values]').on('click', function() {
            var chkvalue = $('input[type=radio][name=values]:checked').val();

            if (chkvalue == 'INPUT'){
                if(conf == "ECB"){
                    $('#LEA_Verify').css('display', 'block');
                    $('#LEA_Search').css('display', 'none');
                }else if(conf == "CBC"){
                    $('#LEA_Verify_CBC').css('display', 'block');
                    $('#LEA_Search_CBC').css('display', 'none');
                }else if(conf == "CTR"){
                    $('#LEA_Verify_CTR').css('display', 'block');
                    $('#LEA_Search_CTR').css('display', 'none');
                }
                
                $('#LSH_Verify').css('display', 'block');
                $('#LSH_Search').css('display', 'none');
            }else {
                if(conf == "ECB"){
                    $('#LEA_Verify').css('display', 'none');
                    $('#LEA_Search').css('display', 'block');
                }else if(conf == "CBC"){
                    $('#LEA_Verify_CBC').css('display', 'none');
                    $('#LEA_Search_CBC').css('display', 'block');
                }else if(conf == "CTR"){
                    $('#LEA_Verify_CTR').css('display', 'none');
                    $('#LEA_Search_CTR').css('display', 'block');
                }
                
                $('#LSH_Verify').css('display', 'none');
                $('#LSH_Search').css('display', 'block');
            }
        });
        
        
    </script>

</body>
</html>
