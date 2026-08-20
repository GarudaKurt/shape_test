pipeline {
    agent any
    
    stages { 
    
        stage('Checkout') { 
             steps {
                 checkout scm 
             }
        }
        triggers { 
            cron('H 0 * * *') 
        }
        environment {
            CI = 'true'
        }
        stage('CompileMain') { 
             steps { 
                 echo 'Running main components'
             
	         sh '''
                    ./main
                  '''
             }
        }
        stage('Build') {
           steps {
               sh ''' 
                   rm -rf build
                   cmake -S . -B build
                   cmake --build build
               '''
           }
        }
        stage('Unit Tests') { 
            steps {
               sh '''
                      ctest --test-dir build --output-on-failure
                  '''
            } 
        }
        stage('For the fix branch') {
             when { 
               branch "fix-*"
             }
             steps {
                echo 'Capture branch fix'
             }  
       }
       stage('For PR') { 
           when {
               branch "PR-*"
           }
           steps {
                echo 'For PR Branch only' 
           }
                
       } 
    }
    post {
        success {
             echo 'Build and unit tests passed!' 
        }
        failure { 
             echo 'Build or unit test failed!' 
       }
       always { 
           echo "Branch/PR: ${env.BRANCH_NAME}"  
       }
    }
} 
