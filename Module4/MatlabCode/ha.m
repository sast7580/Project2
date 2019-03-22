V = xlsread('C:\Users\sarah\OneDrive\Desktop\ECEN5803\Project2\Module4\SineData');
time = V(:,1);
data = V(:,2);
figure
plot(time,data)
xlabel('time (seconds)');
ylabel('amplitude (volts)');
samplingFreq = 40*1004;                    
samplingPeriod = 1/samplingFreq;     
sigLength = length(data);
sigTime = (0:sigLength-1)*samplingPeriod;
figure
plot(1000*sigTime(1:50),X(1:50))
Y = fft(data);
P2 = abs(Y/sigLength);
P1 = P2(1:sigLength/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = samplingFreq*(0:(sigLength/2))/sigLength;
figure
plot(f,P1) 
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
