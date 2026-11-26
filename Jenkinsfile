pipeline {
    agent { label 'Dokcerize' }
    
    triggers { 
        cron('36 10 * * *')
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

        stage('Prepare') {
            steps {
                script {
                    // unique per branch and build; characters such as / are not allowed in tags
                    env.IMAGE = 'shapeclass:' + env.BUILD_TAG.replaceAll('[^A-Za-z0-9_.-]', '-')
                }
                sh 'docker version'
            }
        }
        stage('Build and Unit Tests') {
            steps {
                sh 'docker build --progress=plain --target test --no-cache-filter test .'
            }
        }
        stage('Build Runtime Image') {
            steps {
                sh 'docker build --target runtime -t "$IMAGE" .'
            }
        }
        stage('Run main') {
            when {
                branch 'main'
            }
            steps {
                sh 'docker run --rm "$IMAGE"'
                sh 'docker tag "$IMAGE" shapeclass:latest'
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
           sh 'if [ -n "$IMAGE" ]; then docker image rm "$IMAGE" || true; fi'
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
