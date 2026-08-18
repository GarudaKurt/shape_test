pipeline {
    agent any
    
    stages { 
    
        stage('Checkout') { 
             steps {
                 checkout scm 
             }
        }
        stage('CompileMain') { 
             echo 'Running main components'
             sh '''
               ./main
              '''
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
