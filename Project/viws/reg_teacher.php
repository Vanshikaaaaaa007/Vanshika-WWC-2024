<?php include("../layouts/header.php"); ?>
<?php include("../layouts/nav_login.php");?>

<div class="reg-content">
    <div class="title">
        <i class="fas fa-user-plus"></i> Register Teacher
    </div>
    <div class="body">
        <?php 
            include("../function/function.php");
            if(isset($_POST['register'])){
                $result = reg_teacher($_POST['username'], $_POST['email'], md5($_POST['password']));
                echo $result;
            }
        ?>
        <hr>
        <form action="<?php echo($_SERVER['PHP_SELF']); ?>" method="POST" name="regform" onsubmit="return validateform_reg()">
            <table border="0">
                <tr>
                    <td>
                        Username : 
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="text" name="username" id="username" class="reg-input" placeholder="Username"><span id="regusererr"></span>
                    </td>
                </tr>
                <tr>
                    <td>
                        Email :
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="email" name="email" id="email" class="reg-input" placeholder="Email"><span id="regemailerr"></span>
                    </td>                
                <tr>
                    <td>
                        Password :
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="password" name="password" id="password" class="reg-input" placeholder="Password"><span id="regpasserr"></span>
                    </td>
                </tr>
                <tr>
                    <td>
                        Confirm Password :
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="password" name="cpassword" id="cpassword" class="reg-input" placeholder="Confirm Password"><span id="regcpasserr"></span>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="reset" value="Clear" class="reg-clear-btn"> 
                        <input type="submit" value="Sign Up" name="register" class="reg-btn">
                    </td>
                </tr>
            </table>    
        </form>
        <br>
        Already Have Account ? <a href="login.php">Login</a><br>
        Stundent SignUp ? <a href="reg_std.php">Student</a>
    </div>
</div>

<?php include("../layouts/footer.php"); ?>

<script src="../../js/script.js"></script>
