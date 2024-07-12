export PS1="\[\033[36m\]\u\[\033[m\]@\[\033[32m\]\h:\[\033[33;1m\]\w\[\033[m\]\$ "
export CLICOLOR=1
export LSCOLORS=ExFxBxDxCxegedabagacad
alias ls='ls -GFh'

# Command alias
alias ls='ls -GFh'
alias ll='ls -alF'
alias l='ls -CF'
alias la='ls -A'

# Setting PATH for Python 2.7
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/2.7/bin:${PATH}"
export PATH

# Adding Mysql 
export PATH=/usr/local/mysql/bin:$PATH
alias mysql-root='mysql -u root -p12345678'


# The next line updates PATH for the Google Cloud SDK.
if [ -f '/Users/moshekagan/dev/google-cloud-sdk/path.bash.inc' ]; then . '/Users/moshekagan/dev/google-cloud-sdk/path.bash.inc'; fi

# The next line enables shell command completion for gcloud.
if [ -f '/Users/moshekagan/dev/google-cloud-sdk/completion.bash.inc' ]; then . '/Users/moshekagan/dev/google-cloud-sdk/completion.bash.inc'; fi

# Setting PATH for Python 3.8
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.8/bin:${PATH}"
export PATH

# Setting PATH for Python 3.7
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.7/bin:${PATH}"
export PATH

export JAVA_HOME=$(/usr/libexec/java_home -v 20.0)



# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/Users/moshekagan/opt/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/Users/moshekagan/opt/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/Users/moshekagan/opt/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/Users/moshekagan/opt/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<


# Setting PATH for Python 3.11
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.11/bin:${PATH}"
export PATH


# Load Angular CLI autocompletion.
source <(ng completion script)

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
