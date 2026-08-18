pipeline {
    agent any
    
    stages { 
    
        stage('Checkout) { 
             steps {
                 checkout scm 
             }
        }
     
        stage('Build') {
           steps {
               sh ''' 
                   rm -rf build
                   cmake -S . -B build
                   cmake --build . build
               '''
           }
        }
        stage('Unit Tests') { 
            steps {
               sh '''
                      cd build
                      ctest --output-on-failure
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
