pipeline {
    agent any
    
    triggers { 
        cron('31 10 * * *')
    }
    environment { 
        CI = 'true'
    }
    stages { 
    
        stage('Checkout') { 
             steps {
                 checkout scm 
             }
        }
        stage('CompileMain') { 
             when { 
                 branch "main"
             }
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
       stage('For feature branch') { 
           when { 
                branch "feature-*" 
          }
          steps {
              echo 'For feature branches'
          }
       }
       stage('Pull request to develop') { 
            when { 
                changeRequest(target: 'develop')    
            }
            steps { 
                echo "Running validation for PR: ${env.CHANGE_ID}"
                echo "Source branch: ${env.CHANGE_BRANCH}"
                echo "Target branch: ${env.CHANGE_TARGET}"
            }
       }
       stage('Develop branch') { 
             when {  
                branch 'develop'  
            }
            steps { 
                echo 'develop triggered branch'
            }
       }
       stage('Main branch') { 
             when { 
                branch 'main'
            }
            steps { 
                echo 'Main branch triggered'
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
            script { 
               if(env.CHANGE_ID) { 
                echo "Running validation for PR: ${env.CHANGE_ID}"

                echo "Source branch: ${env.CHANGE_BRANCH}"
                  
                echo "Target branch: ${env.CHANGE_TARGET}"
                }
            }  
       }
    }
} 
